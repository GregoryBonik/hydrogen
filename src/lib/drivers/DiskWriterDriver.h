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
 * $Id: DiskWriterDriver.h,v 1.7 2005/05/01 19:51:40 comix Exp $
 *
 */

#ifndef DISK_WRITER_DRIVER_H
#define DISK_WRITER_DRIVER_H

#include <sndfile.h>

#include <inttypes.h>

#include "GenericDriver.h"
#include "../Object.h"

typedef int  (*audioProcessCallback)(uint32_t, void *);

///
/// Driver for export audio to disk
///
class DiskWriterDriver : public GenericDriver {
	public:
		unsigned m_nSampleRate;
		string m_sFilename;
		unsigned m_nBufferSize;
		audioProcessCallback m_processCallback;
		float* m_pOut_L;
		float* m_pOut_R;


		DiskWriterDriver( audioProcessCallback processCallback, unsigned nSamplerate, std::string sFilename );
		~DiskWriterDriver();

		int init(unsigned nBufferSize);

		int connect();
		void disconnect();

		void write(float* buffer_L, float* buffer_R, unsigned int bufferSize);

		unsigned getBufferSize() {	return m_nBufferSize;	}

		unsigned getSampleRate();
		float* getOut_L() {	return m_pOut_L; }
		float* getOut_R() {	return m_pOut_R; }

		virtual void play();
		virtual void stop();
		virtual void locate( unsigned long nFrame );
		virtual void updateTransportInfo();
		virtual void setBpm(float fBPM);

	private:



};


#endif