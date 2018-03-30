// Vita3K emulator project
// Copyright (C) 2018 Vita3K team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#pragma once

#include <host/state.h>
#include <psp2/types.h>

#include <chrono>
#include <cstdint>

// This is the # of microseconds between January 1, 0001 and January 1, 1970.
// Grabbed from JPSCP
static constexpr auto RTC_OFFSET = 62135596800000000ULL;

// 400 years is a convenient number, since leap days and everything cycle every 400 years.
// 400 years is in other words 20871 full weeks.
constexpr std::uint64_t RTC_400_YEAR_TICKS = 20871ULL * 7 * 24 * 3600 * 1000000;

constexpr auto VITA_CLOCKS_PER_SEC = 1'000'000;

using VitaClocks = std::chrono::duration<std::uint64_t, std::ratio<1, VITA_CLOCKS_PER_SEC>>;

std::uint64_t rtc_base_ticks();
std::uint64_t rtc_get_ticks(const HostState& host);
time_t rtc_timegm(struct tm *tm);
void __RtcPspTimeToTm(tm& val, const SceDateTime& pt);
void __RtcTicksToPspTime(SceDateTime& t, std::uint64_t ticks);
std::uint64_t __RtcPspTimeToTicks(const SceDateTime& pt);
