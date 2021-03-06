/*
 * Copyright (c) 2017, Jonathan Schleifer <js@heap.zone>
 *
 * https://heap.zone/git/objqt.git
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice is present in all copies.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import "QtCoreApplication.h"

#include <QGuiApplication>

@interface QtGUIApplication: QtCoreApplication
@property (readonly) QGuiApplication *qGuiApplication;
@property (copy) OFString *applicationDisplayName;
#if QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
@property (copy) OFString *desktopFileName;
#endif
@property Qt::LayoutDirection layoutDirection;
@property (readonly, copy) OFString *platformName;
@property (readonly) QScreen *primaryScreen;
@property bool quitsOnLastWindowClosed;
@property QIcon windowIcon;

- initWithQGuiApplication: (QGuiApplication*)qGuiApplication;
- (double)devicePixelRatio;
- (bool)isSavingSession;
- (bool)isSessionRestored;
- (OFString*)sessionID;
- (OFString*)sessionKey;
@end

namespace ObjQt {

static OF_INLINE QtGUIApplication*
toOF(QGuiApplication *qGuiApplication)
{
	return [[[QtGUIApplication alloc]
	    initWithQGuiApplication: qGuiApplication] autorelease];
}

static OF_INLINE QGuiApplication*
toQt(QtGUIApplication *GUIApplication)
{
	return [GUIApplication qGuiApplication];
}

}
