#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode  =========================
	ADD_CARD,		// Add Card Action	
	
	SELECT_CARD,	// Select Card Action
	COPY_CARD,		// Copy Card Action
	PASTE_CARD,		// Paste Card Action
	DELETE_CARD,	// Delete Card Action
	MOVE_CARD,		// Move Card Action
	SHUFFLE_CARD,	// Shuffle Card Action
	SAVE_GRID,		// Save Grid Action
	OPEN_GRID,		// Open Grid Action

	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode

	//  [2] Actions of Play Mode    =========================

	ROLL_DICE,		// Roll Dice Action

	INPUT_DICE_VALUE,	// Input Dice Value Action
	NEW_GAME,			// New Game Action

	TO_DESIGN_MODE,	// Go to Design Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif