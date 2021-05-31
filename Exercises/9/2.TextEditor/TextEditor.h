#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QDockWidget>
#include <QDialog>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QCloseEvent>

class TextEditor : public QMainWindow
{
	Q_OBJECT

public:
	TextEditor();

private slots:
	void newFile();
	void newWindow();
	void openFile();
	void save();
	void saveAs();
	void exit();
	void increaseFontSize();
	void decreaseFontSize();
	void changeFontSize();
	void textChanged();

private:
	void createActions();
	void createStatusBar();
	bool isFileSavedOrEmpty();
	
	void closeEvent(QCloseEvent* event);
	
	bool isFileSaved = false;
	QFont* tahomaFont = new QFont("Tahoma", 16);
	QString currentFilePath = "";
	QString currentFileName = "Untitled.txt";
	QPlainTextEdit* textEdit;
};
