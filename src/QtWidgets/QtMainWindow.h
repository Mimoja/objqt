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

#import "QtWidget.h"

#include <QMainWindow>

@interface QtMainWindow: QtWidget
@property (readonly) QMainWindow *qMainWindow;

@property bool animated;
@property bool dockNestingEnabled;
//Todo replace with QFlags<DockOption> @property DockOptions* dockOptions; 
@property bool documentMode;
@property QSize iconSize; 
@property QTabWidget::TabShape tabShape;
@property Qt::ToolButtonStyle toolButtonStyle;
@property bool unifiedTitleAndToolBarOnMac;

typedef enum { AnimatedDocks,
	       AllowNestedDocks,
	       AllowTabbedDocks,
	       ForceTabbedDocks,
	       VerticalTabs,
	       GroupedDragging } DockOption;

- initWithQMainWindow: (QMainWindow*)qMainWindow;
@end

namespace ObjQt {

static OF_INLINE QtMainWindow*
toOF(QMainWindow *qMainWindow)
{
	return [[[QtMainWindow alloc]
	    initWithQMainWindow: qMainWindow] autorelease];
}

static OF_INLINE QMainWindow*
toQt(QtMainWindow *mainWindow)
{
	return [mainWindow qMainWindow];
}

}
