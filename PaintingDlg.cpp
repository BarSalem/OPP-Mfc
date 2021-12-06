
// PaintingDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Painting.h"
#include "PaintingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPaintingDlg dialog



CPaintingDlg::CPaintingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAINTING_DIALOG, pParent)
	, AreaBox(0)
{
	indexMax = 0;
	currentIndex = -1;
	curr_width = 1;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPaintingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, widthBox);
	DDX_Text(pDX, IDC_EDIT2, AreaBox);
}

BEGIN_MESSAGE_MAP(CPaintingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CPaintingDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CPaintingDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CPaintingDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPaintingDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO3, &CPaintingDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON3, &CPaintingDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO4, &CPaintingDlg::OnBnClickedRadio4)
	ON_WM_RBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON5, &CPaintingDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_RADIO5, &CPaintingDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CPaintingDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CPaintingDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CPaintingDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &CPaintingDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &CPaintingDlg::OnBnClickedRadio10)
END_MESSAGE_MAP()


// CPaintingDlg message handlers

BOOL CPaintingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CheckRadioButton(IDC_RADIO1, IDC_RADIO10, IDC_RADIO1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPaintingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPaintingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{	
		CPaintDC dc(this);
		for (int i = 0; i < figs.GetSize(); i++)
		{
			CBrush* oldBrush, temp;
			temp.CreateSolidBrush(figs[i]->col);
			oldBrush = dc.SelectObject(&temp);
			figs[i]->Draw(&dc);
			dc.SelectObject(oldBrush);
		}
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPaintingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPaintingDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	start = point;
	isPressed = true;
	switch (futureFigure)
	{
	case 1:
		figs.Add(new RectangleF(start, start));
		break;
	case 2:
		figs.Add(new EllipseF(start, start));
		break;
	case 3:
		figs.Add(new CircleF(start, start));
		break;
	case 4:
		figs.Add(new LineF(start, start));
		break;
	case 5:
		figs.Add(new TriangleF(start, start));
	case 6:
		currentIndex = -1;
		if (figs.GetSize()!=0)
		{
			for (int i = figs.GetSize() - 1; i >= 0; i--)
			{
				if (figs[i]->isInside(point))
				{
					currentIndex = i;
					curr = figs[i]->getP1();
					break;
				}
			}
			break;
		}
		else
			break;
	case 7:
		currentIndex = -1;
		for (int i = figs.GetSize() - 1 ; i >= 0; i--)
		{
			if (figs[i]->isInside(point))
			{	
				currentIndex = i;
				break;
			}
		}
		break;
	case 8:
		currentIndex = -1;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(point))
			{
				currentIndex = i;
				break;
			}
		}
		break;
	case 9:
		currentIndex = -1;
		int i;
		for (i = figs.GetSize() - 1 ; i >= 0 ; i--)
		{
			if (figs[i]->isInside(point))
			{
				currentIndex = i;
				last = point;
				break;
			}
		}
		break;
	case 10:
		figs.Add(new NorTriangleF(start, start));
		break;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CPaintingDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		CClientDC dc(this);
		if ((futureFigure >= 1 && futureFigure <= 5)|| futureFigure==10)
		{
			end = point;
			figs[figs.GetSize() - 1]->width = curr_width;
			figs[figs.GetSize() - 1]->Redefine(start, end);
			Invalidate();
		}
		if (futureFigure==6)
		{	
			if (currentIndex != -1)
			{
				end = point;
				figs[currentIndex]->Redefine(curr, end);
				Invalidate();
			}
		}
		if (futureFigure == 7)
		{
			if (currentIndex != -1)
			{
				figs[currentIndex]->col = curr_Color;
				CBrush* oldBrush, temp;
				temp.CreateSolidBrush(curr_Color);
				oldBrush = dc.SelectObject(&temp);
				figs[currentIndex]->Draw(&dc);
				dc.SelectObject(oldBrush);
			}
		}
		if (futureFigure == 8)
		{
			if (currentIndex != -1)
			{
				int Area = figs[currentIndex]->Area();
				AreaBox = Area;           
				UpdateData(FALSE);
			}
		}
		if (futureFigure == 9)
		{
			if (currentIndex != -1)
			{
				end = point;
				figs[currentIndex]->Draw(&dc);
				figs[currentIndex]->Redefine(figs[currentIndex]->p1 + (end - last), figs[currentIndex]->p2 + (end-last));
				Invalidate();
			}
		}
		dc.SetROP2(R2_COPYPEN);
		isPressed = false;

	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CPaintingDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPressed)
	{	
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);
		if ((futureFigure >= 1 && futureFigure <= 5) || futureFigure == 10)
		{
			figs[figs.GetSize() - 1]->Draw(&dc);
			end = point;
			figs[figs.GetSize() - 1]->Redefine(start, end);
			figs[figs.GetSize() - 1]->Draw(&dc);
		}
		if(futureFigure==6)
		{
			if (currentIndex != -1)
			{
				figs[currentIndex]->Draw(&dc);
				end = point;
				figs[currentIndex]->Redefine(curr, end);
				figs[currentIndex]->Draw(&dc);
			}
		}
		if (futureFigure == 9)
		{
			if (currentIndex != -1)
			{	
				end = point;
				figs[currentIndex]->Draw(&dc);
				CPoint temp1 = figs[currentIndex]->p1 + (end - last);
				CPoint temp2= figs[currentIndex]->p2 + (end - last);
				figs[currentIndex]->Redefine(temp1, temp2);
				figs[currentIndex]->Draw(&dc);
				last = point;
			}
		}
		dc.SetROP2(R2_COPYPEN);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CPaintingDlg::OnBnClickedRadio1()
{
	futureFigure = 1;
}


void CPaintingDlg::OnBnClickedRadio2()
{
	futureFigure = 2;
}


void CPaintingDlg::OnBnClickedButton1()
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar << 5;
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CPaintingDlg::OnBnClickedButton2()
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		int j;
		ar >> j;
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CPaintingDlg::OnBnClickedRadio3()
{
	futureFigure = 3;
}


void CPaintingDlg::OnBnClickedButton3()
{
	CColorDialog dlg1;
	if (dlg1.DoModal() == IDOK)
	{
		COLORREF color = dlg1.GetColor();
		curr_Color = color;
	}
}


void CPaintingDlg::OnBnClickedRadio4()
{
	futureFigure = 4;
}

void CPaintingDlg::OnRButtonDown(UINT nFlags, CPoint point)
{	
	int i;
	for (i = figs.GetSize() - 1; i >= 0; i--)
	{
		if (figs[i]->isInside(point))
		{	
			figs[i]->~Figure();
			figs.RemoveAt((INT_PTR)i, 1);
			break;
		}
	}
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CPaintingDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{

}


void CPaintingDlg::OnBnClickedButton5()
{	
	for (int i = 0; i <figs.GetSize() ; i++)
	{
		figs[i]->~Figure();
	}
	figs.RemoveAll();
	Invalidate();
}


void CPaintingDlg::OnBnClickedRadio5()
{
	futureFigure = 6;
}


void CPaintingDlg::OnBnClickedRadio6()
{
	futureFigure = 7;
	if (curr_Color == RGB(0, 0, 0));
	{
		MessageBox(_T("To Brush click the 'color' button and choose color!"), _T("almost there!!"), NULL);
	}
}



void CPaintingDlg::OnBnClickedRadio7()
{
	futureFigure = 5;
}


void CPaintingDlg::OnBnClickedRadio8()
{
	futureFigure = 8;
}


void CPaintingDlg::OnBnClickedRadio9()
{
	futureFigure = 9;
}


void CPaintingDlg::OnBnClickedRadio10()
{
	futureFigure = 10;
}
