using System.Runtime.Serialization.Formatters.Binary;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace WinFormsApp5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            InitializeComponents();
            InitializeExplorer();
        }

        private void InitializeComponents()
        {
            // Добавляем StatusStrip
            StatusStrip statusStrip = new StatusStrip();
            ToolStripStatusLabel statusLabel = new ToolStripStatusLabel();
            statusStrip.Items.Add(statusLabel);
            this.Controls.Add(statusStrip);
            statusStrip.Dock = DockStyle.Bottom;

            // Сохраняем ссылку на statusLabel для использования в других методах
            this.statusLabel = statusLabel;
        }

        private ToolStripStatusLabel statusLabel; // Объявляем поле класса

        private void InitializeExplorer()
        {
            // Настройка TreeView
            treeView1.PathSeparator = Path.DirectorySeparatorChar.ToString();
            LoadDrives();

            // Настройка ListView
            listView1.View = View.Details;
            listView1.FullRowSelect = true;
            listView1.MultiSelect = true;
            listView1.Columns.Add("Имя", 200);
            listView1.Columns.Add("Тип", 100);
            listView1.Columns.Add("Размер", 100);
            listView1.Columns.Add("Дата изменения", 150);

            // Контекстное меню
            var contextMenu = new ContextMenuStrip();
            contextMenu.Items.Add("Копировать путь", null, CopyPath_Click);
            contextMenu.Items.Add("Открыть", null, OpenSelected_Click);
            listView1.ContextMenuStrip = contextMenu;

            // Обработчики событий
            treeView1.BeforeExpand += TreeView1_BeforeExpand;
            treeView1.AfterSelect += TreeView1_AfterSelect;
            listView1.SelectedIndexChanged += ListView1_SelectedIndexChanged;
            listView1.MouseDoubleClick += ListView1_MouseDoubleClick;

            // Кнопка переключения
            btnToggle.Text = splitContainer1.Orientation == Orientation.Vertical
                ? "Горизонтально"
                : "Вертикально";
            btnToggle.Click += BtnToggle_Click;
        }

        private void LoadDrives()
        {
            treeView1.Nodes.Clear();
            foreach (DriveInfo drive in DriveInfo.GetDrives())
            {
                if (drive.IsReady)
                {
                    TreeNode node = treeView1.Nodes.Add(drive.Name, $"{drive.Name} ({drive.VolumeLabel})");
                    node.Nodes.Add("temp");
                }
            }
        }

        private void TreeView1_BeforeExpand(object sender, TreeViewCancelEventArgs e)
        {
            e.Node.Nodes.Clear();
            try
            {
                foreach (string dir in Directory.GetDirectories(e.Node.FullPath))
                {
                    TreeNode dirNode = e.Node.Nodes.Add(dir, Path.GetFileName(dir));
                    dirNode.Nodes.Add("temp");
                }
            }
            catch { }
        }

        private void TreeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            LoadFiles(e.Node.FullPath);
        }

        private string currentDirectory;
        private void LoadFiles(string path)
        {
            listView1.Items.Clear();
            currentDirectory = path;
            statusLabel.Text = $"Папка: {path}";

            try
            {
                // Папки
                foreach (string dir in Directory.GetDirectories(path))
                {
                    var dirInfo = new DirectoryInfo(dir);
                    var item = listView1.Items.Add(dirInfo.Name);
                    item.SubItems.Add("Папка");
                    item.SubItems.Add("");
                    item.SubItems.Add(dirInfo.LastWriteTime.ToString());
                    item.Tag = dirInfo.FullName;
                }

                // Файлы
                foreach (string file in Directory.GetFiles(path))
                {
                    var fileInfo = new FileInfo(file);
                    var item = listView1.Items.Add(fileInfo.Name);
                    item.SubItems.Add(fileInfo.Extension);
                    item.SubItems.Add(fileInfo.Length.ToString("N0"));
                    item.SubItems.Add(fileInfo.LastWriteTime.ToString());
                    item.Tag = fileInfo.FullName;
                }
            }
            catch (Exception ex)
            {
                statusLabel.Text = $"Ошибка: {ex.Message}";
            }
        }

        private void ListView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            statusLabel.Text = $"Выбрано: {listView1.SelectedItems.Count} | Папка: {currentDirectory}";
        }

        private void ListView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            OpenSelectedItem();
        }

        private void OpenSelected_Click(object sender, EventArgs e)
        {
            OpenSelectedItem();
        }

        private void OpenSelectedItem()
        {
            if (listView1.SelectedItems.Count == 1)
            {
                var selected = listView1.SelectedItems[0];
                try
                {
                    if (selected.SubItems[1].Text == "Папка")
                    {
                        var node = FindNodeByPath(treeView1.Nodes, selected.Tag.ToString());
                        if (node != null)
                        {
                            treeView1.SelectedNode = node;
                            node.Expand();
                        }
                    }
                    else
                    {
                        System.Diagnostics.Process.Start(selected.Tag.ToString());
                    }
                }
                catch (Exception ex)
                {
                    statusLabel.Text = $"Ошибка открытия: {ex.Message}";
                }
            }
        }

        private TreeNode FindNodeByPath(TreeNodeCollection nodes, string path)
        {
            foreach (TreeNode node in nodes)
            {
                if (node.FullPath.Equals(path, StringComparison.OrdinalIgnoreCase))
                    return node;

                var found = FindNodeByPath(node.Nodes, path);
                if (found != null)
                    return found;
            }
            return null;
        }

        private void CopyPath_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count > 0)
            {
                var paths = new System.Text.StringBuilder();
                foreach (ListViewItem item in listView1.SelectedItems)
                {
                    paths.AppendLine(item.Tag.ToString());
                }
                Clipboard.SetText(paths.ToString());
                statusLabel.Text = "Пути скопированы в буфер обмена";
            }
        }

        private void BtnToggle_Click(object sender, EventArgs e)
        {
            splitContainer1.Orientation = splitContainer1.Orientation == Orientation.Vertical
                ? Orientation.Horizontal
                : Orientation.Vertical;

            btnToggle.Text = splitContainer1.Orientation == Orientation.Vertical
                ? "Горизонтально"
                : "Вертикально";
        }
    }
}
    
