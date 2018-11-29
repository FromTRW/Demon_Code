#include "main_ui.h"

main_ui::main_ui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.image_show->setScaledContents(true);
}

QString Result_Show(QString file_name, double result)
{
	QString result_str;
	result_str.append(file_name.mid(file_name.length() - 38, file_name.length() - 5));
	result_str.append(":");
	file_name = QString::number(result, 'f', 3);
	result_str.append(file_name);
	result_str.append("\n");
	return result_str;
}
//�۵���
void main_ui::Slot_1()
{
	qDebug() << "�۵���" << endl;
	ui.result_show->append("----------------------------�۵�(Bemilsh)���----------------------------");
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.Blemish(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
}

// R/G���
void main_ui::Slot_2()
{
	qDebug() << "R/G���" << endl;
	ui.result_show->append("----------------------------R/G���----------------------------");
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.RG(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
}

// B/G���
void main_ui::Slot_3()
{
	qDebug() << "B/G���" << endl;
	ui.result_show->append("----------------------------B/G���----------------------------");
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.BG(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
}

// ʵ����
void main_ui::Slot_4()
{
	qDebug() << "ʵ����" << endl;
	ui.result_show->append("----------------------------ʵ����:----------------------------");
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.DeadPixel(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
}

// �Ҷ�ֵ���
void main_ui::Slot_5()
{
	ui.result_show->append("----------------------------�Ҷ�ֵ���----------------------------");
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.RI(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
}

// ��ת�Ǽ��
void main_ui::Slot_6()
{
	ui.result_show->append("----------------------------����ͷ��ת�Ǽ��----------------------------");
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.Rotation(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
	
}

// �ӳ����
void main_ui::Slot_7()
{
	ui.result_show->append("----------------------------�ӳ��Ǽ��----------------------------");
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.FOV(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
}

// ˮƽ�Ǽ��
void main_ui::Slot_8()
{
	
	if (ui.param_1->text() == "1")
	{
		camera_detection.camera_number = 1;
		ui.result_show->append("----------------------------��������ͷˮƽ�Ǽ��----------------------------");
	}
	else
	{
		camera_detection.camera_number = 0;
		ui.result_show->append("----------------------------ǰ������ͷˮƽ�Ǽ��----------------------------");
	}
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.Tilt(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
}

// SFR���
void main_ui::Slot_9()
{
	if (ui.param_1->text() == "1")
	{
		camera_detection.camera_number = 1;
		ui.result_show->append("----------------------------��������ͷSFR���----------------------------");
	}
	else
	{
		camera_detection.camera_number = 0;
		ui.result_show->append("----------------------------ǰ������ͷSFR���----------------------------");
	}
	QString result_str;
	for (auto tmp : fileNames)
	{
		double result;
		camera_detection.img_file = tmp.toStdString();
		camera_detection.SFR(result);
		result_str.append(Result_Show(tmp, result));
	}
	ui.result_show->append(result_str);
	
}

//���ļ�
void main_ui::Open_File()
{
	qDebug() << "���ļ�" << endl;
	QFileDialog *fileDialog = new QFileDialog(this);
	//�����ļ��Ի������
	fileDialog->setWindowTitle(tr("��ͼƬ"));
	//����Ĭ���ļ�·��
	fileDialog->setDirectory(".\\");
	//�����ļ�������
	fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
	//���ÿ���ѡ�����ļ�,Ĭ��Ϊֻ��ѡ��һ���ļ�,����ѡ�����ļ���QFileDialog::ExistingFiles
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	
	//������ͼģʽ
	fileDialog->setViewMode(QFileDialog::Detail);
	
	//��ӡ����ѡ����ļ���·��
	if (fileDialog->exec())
	{
		fileNames = fileDialog->selectedFiles();
		QPixmap img = QPixmap(fileNames[0]).scaled(ui.image_show->width(), ui.image_show->height());
		ui.image_show->setPixmap(img);
	}

	
}
main_ui::~main_ui()
{

}
