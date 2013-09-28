// ImageViewerDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "CSkinDialog.h"
#include "ActionDispatchIF.h"
#include "CCustomizedButton.h"
#include "CEasyHyperlink.h"
#include <list>

class ImageProcessor;

// CImageViewerDlg dialog
class CImageViewerDlg : public CSkinDialog, public ActionDispatchIF
{
	typedef CSkinDialog INHERITED;

// Construction
public:
	CImageViewerDlg(CWnd* pParent = NULL);	// standard constructor
	~CImageViewerDlg();

	// Load the skin for the main window.
	virtual void LoadDialogImages();

// Dialog Data
	enum { IDD = IDD_IMAGEVIEWER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	CString		mImageFile;
	ImageProcessor*	mProcessor;

	void DisplayImage(void);
	void ParseUISkinXml(void);

	// --- ActionDispatchIF methods ---
	bool Invoke(IMAGE_FUNCTION funcId);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonAbout();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonInvert();
	afx_msg void OnBnClickedButtonOverlayLogo();
	afx_msg void OnBnClickedButtonReload();
	afx_msg void OnBnClickedButtonOverlaySystime();
	afx_msg void OnBnClickedButtonClean();
	afx_msg void OnBnClickedButtonSaveAs();
	afx_msg void OnBnClickedButtonGreyscale();
	afx_msg void OnBnClickedButtonMin();
	afx_msg void OnBnClickedButtonExit();

private:
	CStatic			mPictureWnd;
	CEasyHyperlink*	mpHyperlink;

	typedef std::list<CCustomizedButton*> ButtonList;
	ButtonList		mButtons;

	typedef std::list<CStatic*> StaticList;
	StaticList		mStatics;
};
