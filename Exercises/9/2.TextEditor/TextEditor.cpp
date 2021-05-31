#include "TextEditor.h"
#include <QInputDialog>

#include "x64/Debug/uic/ui_TextEditor.h"

TextEditor::TextEditor()
	: textEdit(new QPlainTextEdit)
{
	setWindowTitle(currentFileName);
	setCentralWidget(textEdit);
	resize(500, 350);
	createActions();
	createStatusBar();
	connect(textEdit, &QPlainTextEdit::textChanged, this, &TextEditor::textChanged);
}

void TextEditor::createActions()
{
	QMenu* fileMenu = menuBar()->addMenu("&File");

	QAction* newAction = new QAction("&New");
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip("Create a new file");
	connect(newAction, &QAction::triggered, this, &TextEditor::newFile);
	fileMenu->addAction(newAction);

	QAction* newWindowAction = new QAction("New &Window");
	newWindowAction->setShortcut(tr("Ctrl+Shift+N"));
	newWindowAction->setStatusTip("Open a new window");
	connect(newWindowAction, &QAction::triggered, this, &TextEditor::newWindow);
	fileMenu->addAction(newWindowAction);

	QAction* openAction = new QAction("&Open...");
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip("Open an existing file");
	connect(openAction, &QAction::triggered, this, &TextEditor::openFile);
	fileMenu->addAction(openAction);

	QAction* saveAction = new QAction("&Save");
	saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip("Save file");
	connect(saveAction, &QAction::triggered, this, &TextEditor::save);
	fileMenu->addAction(saveAction);

	QAction* saveAsAction = new QAction("Save &As");
	saveAsAction->setShortcut(tr("Ctrl+Shift+S"));
	saveAsAction->setStatusTip("Save file with new name");
	connect(saveAsAction, &QAction::triggered, this, &TextEditor::saveAs);
	fileMenu->addAction(saveAsAction);

	fileMenu->addSeparator();

	QAction* exitAction = new QAction("E&xit");
	exitAction->setStatusTip("Exit the application");
	connect(exitAction, &QAction::triggered, this, &TextEditor::exit);
	fileMenu->addAction(exitAction);

	QMenu* editMenu = menuBar()->addMenu("&Edit");
	QAction* changeFontSize = new QAction("&Change Font Size");
	connect(changeFontSize, &QAction::triggered, this, &TextEditor::changeFontSize);
	editMenu->addAction(changeFontSize);
	QAction* increaseFontSizeAction = new QAction("&Increase Font Size");
	connect(increaseFontSizeAction, &QAction::triggered, this, &TextEditor::increaseFontSize);
	editMenu->addAction(increaseFontSizeAction);
	QAction* decreaseFontSizeAction = new QAction("&Decrease Font Size");
	connect(decreaseFontSizeAction, &QAction::triggered, this, &TextEditor::decreaseFontSize);
	editMenu->addAction(decreaseFontSizeAction);

	textEdit->setFont(*tahomaFont);
}

void TextEditor::createStatusBar()
{
	statusBar()->showMessage("Ready");
}


void TextEditor::newFile()
{
	if (isFileSavedOrEmpty())
	{
		textEdit->setPlainText("");
		isFileSaved = false;
		currentFilePath = "";
		currentFileName = "Untitled.txt";
		setWindowTitle(currentFileName);
	}
}

void TextEditor::newWindow()
{
	TextEditor* newWindow = new TextEditor;
	newWindow->show();
}

void TextEditor::openFile()
{
	if (isFileSavedOrEmpty())
	{
		QString fileName = QFileDialog::getOpenFileName(this,
			tr("Open Image"), "", tr("Text Files (*.txt);;All Files (*.*)"));

		QFile file(fileName);
		if (!file.open(QFile::ReadOnly | QFile::Text)) {
			QMessageBox::warning(this, tr("Warning"),
				tr("Cannot read file %1:\n%2.")
				.arg(QDir::toNativeSeparators(fileName), file.errorString()));
			file.close();
			return;
		}

		QTextStream in(&file);
		textEdit->setPlainText(in.readAll());
		isFileSaved = true;
		currentFilePath = fileName;
		currentFileName = fileName.split('/').last();
		setWindowTitle(currentFileName);
		statusBar()->showMessage(tr("File loaded"), 2000);
		file.close();
	}
}

void TextEditor::save()
{
	if (!currentFilePath.isEmpty())
	{
		QFile file(currentFilePath);
		if (file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QTextStream out(&file);
			out << textEdit->toPlainText();
			isFileSaved = true;
			setWindowTitle(currentFileName);
			statusBar()->showMessage(tr("File saved"), 2000);
		}
		else
			QMessageBox::warning(this, tr("Warning"),
				tr("Cannot read file %1:\n%2.")
				.arg(currentFilePath, file.errorString()));

		file.close();
	}
	else
		saveAs();
}

void TextEditor::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
		"Untitled.txt",
		tr("Text Files (*.txt);;All Files (*.*)"));

	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		currentFilePath = fileName;
		currentFileName = currentFilePath.split('/').last();
		QTextStream out(&file);
		out << textEdit->toPlainText();
		isFileSaved = true;
		setWindowTitle(currentFileName);
		statusBar()->showMessage(tr("File saved"), 2000);
	}
	else
		QMessageBox::warning(this, tr("Warning"),
			tr("Cannot read file %1:\n%2.")
			.arg(currentFilePath, file.errorString()));
}

void TextEditor::closeEvent(QCloseEvent* event)
{
	if (isFileSavedOrEmpty())
		this->close();
	else
		event->ignore();
}

void TextEditor::exit()
{
	this->close();
}

void TextEditor::increaseFontSize()
{
	int currentSize = tahomaFont->pointSize();
	tahomaFont->setPointSize(currentSize + 1);
	textEdit->setFont(*tahomaFont);
}

void TextEditor::decreaseFontSize()
{
	int currentSize = tahomaFont->pointSize();
	if (currentSize > 1)
	{
		tahomaFont->setPointSize(currentSize - 1);
		textEdit->setFont(*tahomaFont);
	}
}

void TextEditor::changeFontSize()
{
	int fontSize = QInputDialog::getInt(this, "Font Size", "Enter Font Size", tahomaFont->pointSize(), 1, 450);
	if (fontSize > 0)
	{
		tahomaFont->setPointSize(fontSize);
		textEdit->setFont(*tahomaFont);
	}
}


void TextEditor::textChanged()
{
	isFileSaved = false;
	statusBar()->showMessage("File is not saved");
	setWindowTitle("*" + currentFileName);
}

bool TextEditor::isFileSavedOrEmpty()
{
	if (!isFileSaved && (currentFileName != "Untitled.txt" || textEdit->toPlainText() != ""))
	{
		QMessageBox::StandardButton replay = QMessageBox::question(this,
			"Warning",
			"You have unsaved changes. do you still want to continue?",
			QMessageBox::Yes | QMessageBox::No);
		if (replay == QMessageBox::No)
			return false;
	}

	return true;
}