/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "ghostergram/ghoster_branding.h"

#include "core/version.h"

namespace ghostergram {

QString AppName() {
	return QString::fromUtf8(::AppName.utf8());
}

QString WithAppName(QString text) {
	return text.replace(u"Telegram"_q, AppName());
}

} // namespace ghostergram
