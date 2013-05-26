#pragma once

/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "DVDInputStream.h"

class CDVDInputStreamMemory : public CDVDInputStream
{
public:
  CDVDInputStreamMemory();
  virtual ~CDVDInputStreamMemory();
  virtual bool Open(const char* strFile, const std::string& content);
  virtual void Close();
  virtual int Read(BYTE* buf, int buf_size);
  virtual int64_t Seek(int64_t offset, int whence);
  virtual bool IsEOF();
  virtual int64_t GetLength();

protected:
  BYTE* m_pData;
  int   m_iDataSize;
  int   m_iDataPos;
};
