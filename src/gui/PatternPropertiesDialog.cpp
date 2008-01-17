/*
 * Hydrogen
 * Copyright(c) 2002-2005 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Id: PatternPropertiesDialog.cpp,v 1.6 2005/05/01 19:50:58 comix Exp $
 *
 */

#include "PatternPropertiesDialog.h"
#include "lib/Hydrogen.h"
#include "Skin.h"


PatternPropertiesDialog::PatternPropertiesDialog(QWidget* parent, Pattern *pattern) : PatternPropertiesDialog_UI(parent) {
	setCaption( trUtf8( "Pattern properties" ) );
	setIcon( QPixmap( Skin::getImagePath().c_str() + QString( "/icon32.png") ) );

	this->pattern = pattern;

	patternNameTxt->setText( trUtf8( (pattern->m_sName.c_str() ) ) );
	patternNameTxt->selectAll();
}




/**
 * Destructor
 */
PatternPropertiesDialog::~PatternPropertiesDialog() {
}



/**
 *
 */
void PatternPropertiesDialog::cancelButtonClicked() {
	reject();
}



/**
 *
 */
void PatternPropertiesDialog::okButtonClicked() {
	string pattName = patternNameTxt->text().latin1();

	pattern->m_sName = pattName;
	accept();
}



/**
 * Do some name check
 */
void PatternPropertiesDialog::textChanged() {

	bool valid = true;

	string pattName = patternNameTxt->text().latin1();
	if (pattName == "") {
		valid = false;
	}

	Hydrogen *engine = Hydrogen::getInstance();
	Song *song = engine->getSong();
	PatternList *patternList = song->getPatternList();

	for (uint i = 0; i < patternList->getSize(); i++) {
		Pattern *pat = patternList->get(i);

		if ( pat->m_sName == pattName) {
			valid = false;
			break;
		}
	}

	if (valid) {
		okBtn->setEnabled(true);
	}
	else {
		okBtn->setEnabled(false);
	}
}

