/*
 * Copyright (c) 2017, Maximilian Schander <max-schander@freenet.de>
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

#import "QtAbstractButton.h"

#include <QMenu>
#include <QPushButton>

@interface QtPushButton: QtAbstractButton
@property (readonly) QPushButton* qPushButton;
@property (getter=menu) QMenu* menu;
@property (getter=autoDefault) bool autoDefault;
@property (getter=isDefault, setter=setDefault:) bool default_;
@property (getter=isFlat) bool flat;


- initWithQPushButton: (QPushButton*)qPushButton;
- initWithText: (OFString*) text;
- initWithIcon: (QIcon) icon Text: (OFString*)text;

@end

namespace ObjQt {

static OF_INLINE QtPushButton*
toOF(QPushButton *qPushButton)
{
	return [[[QtPushButton alloc]
	    initWithQPushButton: qPushButton] autorelease];
}

static OF_INLINE QPushButton*
toQt(QtPushButton *pushButton)
{
	return [pushButton qPushButton];
}

}
