#include "Question.h"

Question::Question(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.question_ok,SIGNAL(clicked()),this,SLOT(OnOk()));
	connect(ui.question_cancel,SIGNAL(clicked()),this,SLOT(OnCancel()));
}

Question::~Question()
{
}

void Question::OnOk()
{
	answer = ui.question_input->text();
	accept();
}

void Question::OnCancel()
{
	reject();
}