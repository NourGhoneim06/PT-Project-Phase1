#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	if (v >= 0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	return false;

}

bool CellPosition::SetHCell(int h)
{
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	return false;

}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (vCell >= 0 && vCell < NumVerticalCells && hCell >= 0 && hCell < NumHorizontalCells)
		return true;
	return false;

}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	if (!cellPosition.IsValidCell())
		return -1;

	int cellNum = (NumVerticalCells - 1 - cellPosition.VCell()) * NumHorizontalCells + cellPosition.HCell() + 1;
	return cellNum;

}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	if (cellNum < 1 || cellNum > NumVerticalCells * NumHorizontalCells)
		return position;

	position.SetVCell(NumVerticalCells - 1 - (cellNum - 1) / NumHorizontalCells);
	position.SetHCell((cellNum - 1) % NumHorizontalCells);

	return position;

}

void CellPosition::AddCellNum (int addedNum)
{
	if (!IsValidCell())
		return;

	CellPosition newPos = GetCellPositionFromNum(GetCellNum() + addedNum);
	if (newPos.IsValidCell())
		(*this) = newPos;

}