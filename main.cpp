#include "main.h"
#include "rc.h"

int SinDialog::IDD(){
	return IDD_LEGEND; 
}

bool SinDialog::OnInitDialog(){
	SetReal(IDC_EDIT1, period);
	SetText(IDC_EDIT2, text);
	return true;
}

bool SinDialog::OnOK() {
	try {
		period = GetInt(IDC_EDIT1);
		text = GetText(IDC_EDIT2);
	}
	catch (XCtrl&){
		MessageBox(*this, "Make sure every field is filled in with a value", "ERR: Blank Field", MB_ICONWARNING);
		return false;
	}
	return true;
}


void MainWindow::OnPaint(HDC hdc){
}

void MainWindow::OnCommand(int id){
	switch(id){
	case ID_LEGEND: {
		SinDialog sinDialog;
		sinDialog.period = winperiod;
		sinDialog.text = wintext;
		if (sinDialog.DoModal(0, *this) == IDOK) {
			winperiod = sinDialog.period;
			wintext = sinDialog.text;
		}

		InvalidateRect(*this, NULL, true);
		break;
	}
		case ID_EXIT: 
			DestroyWindow(*this); 
			break;
	}
}

void MainWindow::OnDestroy(){
	::PostQuitMessage(0);
} 


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	Application app;
	MainWindow wnd;	
	wnd.Create(NULL, WS_OVERLAPPEDWINDOW | WS_VISIBLE, "NWP", 
		(int)LoadMenu(hInstance, MAKEINTRESOURCE(IDM_MAIN)));	
	return app.Run();
}

