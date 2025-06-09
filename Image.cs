using System.Drawing.Imaging;
using System.Windows.Forms;

namespace WinFormsApp6
{
    public partial class Form1 : Form
    {
            private Bitmap currentImage;
            private Color filterColor = Color.Transparent;

            public Form1()
            {
                InitializeComponent();
                InitializeToolStrip();
                InitializeContextMenu();
                UpdateUI();
            }

            private void InitializeToolStrip()
            {
                ToolStrip toolStrip = new ToolStrip();
                toolStrip.Dock = DockStyle.Top;

                
                ToolStripButton openButton = new ToolStripButton("Открыть");
                openButton.Click += (s, e) => OpenImage();

                ToolStripButton saveButton = new ToolStripButton("Сохранить");
                saveButton.Click += (s, e) => SaveImage();

                ToolStripButton filterButton = new ToolStripButton("Фильтр");
                filterButton.Click += (s, e) => ApplyColorFilter();

                ToolStripButton resetButton = new ToolStripButton("Сброс");
                resetButton.Click += (s, e) => ResetImage();

                toolStrip.Items.AddRange(new ToolStripItem[] { openButton, saveButton, filterButton, resetButton });

                this.Controls.Add(toolStrip);
            }

            private void InitializeContextMenu()
            {
                ContextMenuStrip contextMenu = new ContextMenuStrip();

                ToolStripMenuItem openMenuItem = new ToolStripMenuItem("Открыть");
                openMenuItem.Click += (s, e) => OpenImage();

                ToolStripMenuItem saveMenuItem = new ToolStripMenuItem("Сохранить");
                saveMenuItem.Click += (s, e) => SaveImage();

                ToolStripMenuItem filterMenuItem = new ToolStripMenuItem("Применить фильтр");
                filterMenuItem.Click += (s, e) => ApplyColorFilter();

                ToolStripMenuItem resetMenuItem = new ToolStripMenuItem("Сбросить изменения");
                resetMenuItem.Click += (s, e) => ResetImage();

                contextMenu.Items.AddRange(new ToolStripItem[] { openMenuItem, saveMenuItem, filterMenuItem, resetMenuItem });

                pictureBox.ContextMenuStrip = contextMenu;
            }

            private void OpenImage()
            {
                using (OpenFileDialog openFileDialog = new OpenFileDialog())
                {
                    openFileDialog.Filter = "Изображения (*.bmp;*.jpg;*.jpeg;*.png;*.gif)|*.bmp;*.jpg;*.jpeg;*.png;*.gif|Все файлы (*.*)|*.*";
                    openFileDialog.RestoreDirectory = true;

                    if (openFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        try
                        {
                            currentImage = new Bitmap(openFileDialog.FileName);
                            pictureBox.Image = currentImage;
                            UpdateUI();
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show($"Ошибка при загрузке изображения: {ex.Message}", "Ошибка",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }
                    }
                }
            }

            private void SaveImage()
            {
                if (pictureBox.Image == null)
                {
                    MessageBox.Show("Нет изображения для сохранения", "Предупреждение",
                        MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                using (SaveFileDialog saveFileDialog = new SaveFileDialog())
                {
                    saveFileDialog.Filter = "JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg|PNG (*.png)|*.png|BMP (*.bmp)|*.bmp|GIF (*.gif)|*.gif";
                    saveFileDialog.FilterIndex = 1;
                    saveFileDialog.RestoreDirectory = true;

                    if (saveFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        try
                        {
                            ImageFormat format = ImageFormat.Jpeg;

                            switch (Path.GetExtension(saveFileDialog.FileName).ToLower())
                            {
                                case ".png":
                                    format = ImageFormat.Png;
                                    break;
                                case ".bmp":
                                    format = ImageFormat.Bmp;
                                    break;
                                case ".gif":
                                    format = ImageFormat.Gif;
                                    break;
                            }

                            pictureBox.Image.Save(saveFileDialog.FileName, format);
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show($"Ошибка при сохранении изображения: {ex.Message}", "Ошибка",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }
                    }
                }
            }

            private void ApplyColorFilter()
            {
                if (pictureBox.Image == null)
                {
                    MessageBox.Show("Нет изображения для обработки", "Предупреждение",
                        MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                using (ColorDialog colorDialog = new ColorDialog())
                {
                    if (colorDialog.ShowDialog() == DialogResult.OK)
                    {
                        filterColor = colorDialog.Color;
                        ApplyFilter();
                    }
                }
            }

            private void ApplyFilter()
            {
                if (currentImage == null) return;

                Bitmap filteredImage = new Bitmap(currentImage.Width, currentImage.Height);

                for (int x = 0; x < currentImage.Width; x++)
                {
                    for (int y = 0; y < currentImage.Height; y++)
                    {
                        Color originalColor = currentImage.GetPixel(x, y);
                        Color newColor = Color.FromArgb(
                            (originalColor.R + filterColor.R) / 2,
                            (originalColor.G + filterColor.G) / 2,
                            (originalColor.B + filterColor.B) / 2);

                        filteredImage.SetPixel(x, y, newColor);
                    }
                }

                pictureBox.Image = filteredImage;
                UpdateUI();
            }

            private void ResetImage()
            {
                if (currentImage != null)
                {
                    pictureBox.Image = currentImage;
                    filterColor = Color.Transparent;
                    UpdateUI();
                }
            }

            private void UpdateUI()
            {
                bool hasImage = pictureBox.Image != null;
                saveToolStripMenuItem.Enabled = hasImage;
                filterToolStripMenuItem.Enabled = hasImage;
                resetToolStripMenuItem.Enabled = hasImage;
            }

            private void MainForm_Load(object sender, EventArgs e)
            {
                pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
                pictureBox.BackColor = Color.White;
                pictureBox.BorderStyle = BorderStyle.FixedSingle;
            }
        }
    }
