#ifndef MAIN_UI_H
#define MAIN_UI_H
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include<QDebug>
#include "ui_main_ui.h"
#include "QFileDialog"
#include"camera-detection.h"
class main_ui : public QMainWindow
{
	Q_OBJECT

public:
	main_ui(QWidget *parent = 0);
	~main_ui();
	CameraDetection camera_detection;
protected:
	QString file_path;
	QStringList fileNames;
protected slots:
	void Slot_1();//�۵���
	void Slot_2();// R/G���
	void Slot_3();// B/G���
	void Slot_4();// �ӳ��Ǽ��
	void Slot_5();// ��ת�ǼӲ�
	void Slot_6();// ��б�Ǽ��
	void Slot_7();// SFR���
	void Slot_8();// �Ҷ�ֵ���
	void Slot_9();// ʵ����
	void Open_File(); //���ļ�
private:
	Ui::main_uiClass ui;
};

#endif // MAIN_UI_H
