// MIMICSRECTANGLECTL.CPP : Mimics Rectangle Control Related Interface Definition.
//
// This is a part of the SatView(TM) spacecraft operating system.
// Copyrightę 1992-2016 by BINARY SPACE, Switzerland.
// All rights reserved.
//
// This source code contains the definition of the mimics rectangle
// control related interface.
//
/**********************************************************************
* Modifications:                                                     *
*====================================================================*
* Date       | Release | Comments                                    *
*------------|---------|---------------------------------------------*
* 2000/01/17 | 1.00.00 | Initial creation. [AW]                      *
**********************************************************************/

#include "Mimics.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



////////////////////////////////////////////////////////////////////////////
// CMimicsRectangleCtrlDispatchDriver properties

VOID CMimicsRectangleCtrlDispatchDriver::SetStyle(INT nStyle)
{
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_STYLE));

	SetProperty(GetDispatchID(szDispatch), VT_I4, nStyle);
}

INT CMimicsRectangleCtrlDispatchDriver::GetStyle() CONST
{
	INT  nStyle;
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_STYLE));

	GetProperty(GetDispatchID(szDispatch), VT_I4, &nStyle);
	return nStyle;
}

VOID CMimicsRectangleCtrlDispatchDriver::SetBorderSize(INT nSize)
{
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_BORDERSIZE));

	SetProperty(GetDispatchID(szDispatch), VT_I4, nSize);
}

INT CMimicsRectangleCtrlDispatchDriver::GetBorderSize() CONST
{
	INT  nSize;
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_BORDERSIZE));

	GetProperty(GetDispatchID(szDispatch), VT_I4, &nSize);
	return nSize;
}

VOID CMimicsRectangleCtrlDispatchDriver::SetBorderStyle(INT nStyle)
{
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_BORDERSTYLE));

	SetProperty(GetDispatchID(szDispatch), VT_I4, nStyle);
}

INT CMimicsRectangleCtrlDispatchDriver::GetBorderStyle() CONST
{
	INT  nStyle;
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_BORDERSTYLE));

	GetProperty(GetDispatchID(szDispatch), VT_I4, &nStyle);
	return nStyle;
}

VOID CMimicsRectangleCtrlDispatchDriver::SetBorderColor(COLORREF nColor)
{
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_BORDERCOLOR));

	SetProperty(GetDispatchID(szDispatch), VT_COLOR, nColor);
}

COLORREF CMimicsRectangleCtrlDispatchDriver::GetBorderColor() CONST
{
	COLORREF  nColor;
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_BORDERCOLOR));

	GetProperty(GetDispatchID(szDispatch), VT_COLOR, &nColor);
	return nColor;
}

VOID CMimicsRectangleCtrlDispatchDriver::SetInteriorColor(COLORREF nColor)
{
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_INTERIORCOLOR));

	SetProperty(GetDispatchID(szDispatch), VT_COLOR, nColor);
}

COLORREF CMimicsRectangleCtrlDispatchDriver::GetInteriorColor() CONST
{
	COLORREF  nColor;
	_bstr_t  szDispatch(STRING(IDS_MIMICSPROPERTY_INTERIORCOLOR));

	GetProperty(GetDispatchID(szDispatch), VT_COLOR, &nColor);
	return nColor;
}

/////////////////////////////////////////////////////////////////////////////
// CMimicsRectangleCtrlDispatchDriver operations

VOID CMimicsRectangleCtrlDispatchDriver::SetInteriorHatch(INT nHatch, COLORREF nColor)
{
	_bstr_t  szDispatch(STRING(IDS_MIMICSMETHOD_SETINTERIORHATCH));
	static BYTE  pParameters[] = VTS_I4 VTS_COLOR;

	GetDispatchDriver()->InvokeHelper(GetDispatchID(szDispatch), DISPATCH_METHOD, VT_EMPTY, (void *)NULL, pParameters, nHatch, nColor);
}

BOOL CMimicsRectangleCtrlDispatchDriver::GetInteriorHatch(INT &nHatch, COLORREF &nColor) CONST
{
	BOOL  bHatch;
	_bstr_t  szDispatch(STRING(IDS_MIMICSMETHOD_GETINTERIORHATCH));
	static BYTE  pParameters[] = VTS_PI4 VTS_PCOLOR;

	GetDispatchDriver()->InvokeHelper(GetDispatchID(szDispatch), DISPATCH_METHOD, VT_BOOL, &bHatch, pParameters, &nHatch, &nColor);
	return bHatch;
}


IMPLEMENT_DYNCREATE(CMimicsRectangleCtrl, CMimicsCtrl)

/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMimicsRectangleCtrl, CMimicsCtrl)
	//{{AFX_MSG_MAP(CMimicsRectangleCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CMimicsRectangleCtrl, CMimicsCtrl)
	//{{AFX_DISPATCH_MAP(CMimicsRectangleCtrl)
	DISP_PROPERTY_EX(CMimicsRectangleCtrl, "Style", GetStyle, SetStyle, VT_I4)
	DISP_PROPERTY_EX(CMimicsRectangleCtrl, "BorderSize", GetBorderSize, SetBorderSize, VT_I4)
	DISP_PROPERTY_EX(CMimicsRectangleCtrl, "BorderStyle", GetBorderStyle, SetBorderStyle, VT_I4)
	DISP_PROPERTY_EX(CMimicsRectangleCtrl, "BorderColor", GetBorderColor, SetBorderColor, VT_COLOR)
	DISP_PROPERTY_EX(CMimicsRectangleCtrl, "InteriorColor", GetInteriorColor, SetInteriorColor, VT_COLOR)
	DISP_FUNCTION(CMimicsRectangleCtrl, "SetInteriorHatch", SetInteriorHatch, VT_EMPTY, VTS_I4 VTS_COLOR)
	DISP_FUNCTION(CMimicsRectangleCtrl, "GetInteriorHatch", GetInteriorHatch, VT_BOOL, VTS_PI4 VTS_PCOLOR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CMimicsRectangleCtrl, CMimicsCtrl)
	//{{AFX_EVENT_MAP(CMimicsRectangleCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMimicsRectangleCtrl, 2)
	PROPPAGEID(CMimicsRectangleGeneralPage::guid)
	PROPPAGEID(CMimicsRectangleOutlinePage::guid)
END_PROPPAGEIDS(CMimicsRectangleCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMimicsRectangleCtrl, "MIMICS.MimicsRectangleCtrl.1", 0xd9b0d9ff, 0xc96c, 0x11d3, 0xb5, 0xe7, 0, 0x60, 0x8, 0x2d, 0x53, 0x89)

/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CMimicsRectangleCtrl, CMimicsApp::guidApp, CMimicsApp::wAppVerMajor, CMimicsApp::wAppVerMinor)

/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DMimicsRectangle = { 0xd9b0d9fd,0xc96c,0x11d3,{ 0xb5,0xe7,0,0x60,0x8,0x2d,0x53,0x89 } };
const IID BASED_CODE IID_DMimicsRectangleEvents = { 0xd9b0d9fe,0xc96c,0x11d3,{ 0xb5,0xe7,0,0x60,0x8,0x2d,0x53,0x89 } };

/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE  dwMimicsRectangleOleMisc =
OLEMISC_ACTIVATEWHENVISIBLE |
OLEMISC_SETCLIENTSITEFIRST |
OLEMISC_INSIDEOUT |
OLEMISC_CANTLINKINSIDE |
OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMimicsRectangleCtrl, IDS_MIMICSRECTANGLECTRL_DESCRIPTIVENAME, dwMimicsRectangleOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CMimicsRectangleCtrl::CMimicsRectangleCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMimicsRectangleCtrl

BOOL CMimicsRectangleCtrl::CMimicsRectangleCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	return((bRegister) ? AfxOleRegisterControlClass(AfxGetInstanceHandle(), m_clsid, m_lpszProgID, IDS_MIMICSRECTANGLECTRL_DESCRIPTIVENAME, IDB_MIMICSRECTANGLECTRL, afxRegApartmentThreading, dwMimicsRectangleOleMisc, CMimicsApp::guidApp, CMimicsApp::wAppVerMajor, CMimicsApp::wAppVerMinor) : AfxOleUnregisterClass(m_clsid, m_lpszProgID));
}


/////////////////////////////////////////////////////////////////////////////
// CMimicsRectangleCtrl

CMimicsRectangleCtrl::CMimicsRectangleCtrl() : CMimicsCtrl()
{
	m_szType = STRING(IDS_MIMICSRECTANGLECTRL_TYPE);
	InitializeIIDs(&IID_DMimicsRectangle, &IID_DMimicsRectangleEvents);
	InitializeProps();
}

VOID CMimicsRectangleCtrl::InitializeProps()
{
	m_nStyle = MIMICSRECTANGLECTRL_TYPE_NORMAL;
	m_nBorderSize = 1;
	m_nBorderStyle = PS_SOLID;
	m_nBorderColor = TranslateColor(VGA_COLOR_BLACK);
	m_nHatchColor = TranslateColor(VGA_COLOR_BLACK);
	m_nInteriorColor = TranslateColor(VGA_COLOR_WHITE);
	m_nInteriorHatch = -1;
}

void CMimicsRectangleCtrl::SetStyle(LONG nStyle)
{
	if (nStyle != m_nStyle)
	{
		m_nStyle = nStyle;
		Refresh();
	}
}

LONG CMimicsRectangleCtrl::GetStyle() CONST
{
	return m_nStyle;
}

void CMimicsRectangleCtrl::SetBorderSize(LONG nSize)
{
	if (nSize != m_nBorderSize)
	{
		m_nBorderSize = nSize;
		Refresh();
	}
}

LONG CMimicsRectangleCtrl::GetBorderSize() CONST
{
	return m_nBorderSize;
}

void CMimicsRectangleCtrl::SetBorderStyle(LONG nStyle)
{
	if (nStyle != m_nBorderStyle)
	{
		m_nBorderStyle = nStyle;
		Refresh();
	}
}

LONG CMimicsRectangleCtrl::GetBorderStyle() CONST
{
	return m_nBorderStyle;
}

void CMimicsRectangleCtrl::SetBorderColor(OLE_COLOR nColor)
{
	if (nColor != m_nBorderColor)
	{
		m_nBorderColor = nColor;
		Refresh();
	}
}

OLE_COLOR CMimicsRectangleCtrl::GetBorderColor() CONST
{
	return m_nBorderColor;
}

void CMimicsRectangleCtrl::SetInteriorColor(OLE_COLOR nColor)
{
	if (nColor != m_nInteriorColor)
	{
		m_nInteriorColor = nColor;
		Refresh();
	}
}

OLE_COLOR CMimicsRectangleCtrl::GetInteriorColor() CONST
{
	return m_nInteriorColor;
}

void CMimicsRectangleCtrl::SetInteriorHatch(LONG nHatch, OLE_COLOR nColor)
{
	if (nHatch != m_nInteriorHatch || nColor != m_nHatchColor)
	{
		m_nInteriorHatch = nHatch;
		m_nHatchColor = nColor;
		Refresh();
	}
}

BOOL CMimicsRectangleCtrl::GetInteriorHatch(LONG *pHatch, OLE_COLOR *pColor) CONST
{
	CopyMemory(pHatch, &m_nInteriorHatch, sizeof(LONG));
	CopyMemory(pColor, &m_nHatchColor, sizeof(COLORREF));
	return((m_nInteriorHatch >= 0) ? TRUE : FALSE);
}

VOID CMimicsRectangleCtrl::DrawCtrl(HDC hDC, CONST RECT *pRect, BOOL bShape)
{
	INT  nMode;
	HPEN  hOldPen;
	HPEN  hBorderPen;
	HBRUSH  hOldBrush;
	HBRUSH  hInteriorBrush;
	HBITMAP  hInteriorBitmap;
	LOGBRUSH  sInteriorBrush;
	COLORREF  nOldColor[2];

	if ((hBorderPen = CreatePen(PS_GEOMETRIC | PS_ENDCAP_FLAT | PS_JOIN_MITER | m_nBorderStyle, m_nBorderSize, GetNearestColor(hDC, (!bShape) ? m_nBorderColor : VGA_COLOR_WHITE))))
	{
		if ((hInteriorBitmap = LoadBitmap(GetModuleInstance(), (m_nInteriorHatch == HT_SOLID || m_nInteriorHatch < 0) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHSOLID) : ((m_nInteriorHatch == HT_HORIZONTAL) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHHORIZONTAL) : ((m_nInteriorHatch == HT_VERTICAL) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHVERTICAL) : ((m_nInteriorHatch == HT_BDIAGONAL) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHDIAGONALDOWN) : ((m_nInteriorHatch == HT_FDIAGONAL) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHDIAGONALUP) : ((m_nInteriorHatch == HT_CROSS) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHCROSS) : ((m_nInteriorHatch == HT_DIAGCROSS) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHCROSSDIAGONAL) : ((m_nInteriorHatch == HT_LPOINTS) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHPOINTSLOW) : ((m_nInteriorHatch == HT_MPOINTS) ? MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHPOINTSMEDIUM) : MAKEINTRESOURCE(IDB_MIMICSOBJECTCTLHATCHPOINTSHIGH))))))))))))
		{
			sInteriorBrush.lbStyle = (m_nInteriorColor != (COLORREF)-1) ? ((m_nInteriorHatch > 0) ? BS_PATTERN : BS_SOLID) : BS_HOLLOW;
			sInteriorBrush.lbColor = (sInteriorBrush.lbStyle == BS_SOLID) ? GetNearestColor(hDC, (!bShape) ? m_nInteriorColor : VGA_COLOR_WHITE) : 0;
			sInteriorBrush.lbHatch = (sInteriorBrush.lbStyle == BS_PATTERN) ? (ULONG_PTR)hInteriorBitmap : (ULONG_PTR)NULL;
			if ((hInteriorBrush = CreateBrushIndirect(&sInteriorBrush)) != (HBRUSH)NULL)
			{
				if ((hOldPen = (HPEN)SelectObject(hDC, hBorderPen)) != (HPEN)NULL)
				{
					if ((hOldBrush = (HBRUSH)SelectObject(hDC, hInteriorBrush)))
					{
						for (nMode = SetBkMode(hDC, OPAQUE), nOldColor[0] = SetBkColor(hDC, GetNearestColor(hDC, (!bShape) ? m_nInteriorColor : VGA_COLOR_WHITE)), nOldColor[1] = SetTextColor(hDC, GetNearestColor(hDC, (!bShape) ? m_nHatchColor : VGA_COLOR_WHITE)); m_nStyle & MIMICSRECTANGLECTRL_TYPE_NORMAL; )
						{
							Rectangle(hDC, pRect->left + m_nBorderSize / 2, pRect->top + m_nBorderSize / 2, pRect->right - m_nBorderSize / 2 - m_nBorderSize % 2, pRect->bottom - m_nBorderSize / 2 - m_nBorderSize % 2);
							break;
						}
						for (; m_nStyle & MIMICSRECTANGLECTRL_TYPE_ROUND; )
						{
							RoundRect(hDC, pRect->left + m_nBorderSize / 2, pRect->top + m_nBorderSize / 2, pRect->right - m_nBorderSize / 2 - m_nBorderSize % 2, pRect->bottom - m_nBorderSize / 2 - m_nBorderSize % 2, min((pRect->right - pRect->left - m_nBorderSize / 2 - m_nBorderSize / 2 - m_nBorderSize % 2) / 4, (pRect->bottom - pRect->top - m_nBorderSize / 2 - m_nBorderSize / 2 - m_nBorderSize % 2) / 4), min((pRect->right - pRect->left - m_nBorderSize / 2 - m_nBorderSize / 2 - m_nBorderSize % 2) / 4, (pRect->bottom - pRect->top - m_nBorderSize / 2 - m_nBorderSize / 2 - m_nBorderSize % 2) / 4));
							break;
						}
						SetBkMode(hDC, nMode);
						SetBkColor(hDC, nOldColor[0]);
						SetTextColor(hDC, nOldColor[1]);
						SelectObject(hDC, hOldBrush);
					}
					SelectObject(hDC, hOldPen);
				}
				DeleteObject(hInteriorBrush);
			}
			DeleteObject(hInteriorBitmap);
		}
		DeletePen(hBorderPen);
	}
}

void CMimicsRectangleCtrl::DoPropExchange(CPropExchange *pPX)
{
	ExchangeVersion(pPX, MAKELONG(CMimicsApp::wAppVerMinor, CMimicsApp::wAppVerMajor));
	CMimicsCtrl::DoPropExchange(pPX);
}

/////////////////////////////////////////////////////////////////////////////
// CMimicsRectangleCtrl message handlers
