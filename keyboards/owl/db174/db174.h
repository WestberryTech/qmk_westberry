/* Copyright (C) 2022 Westberry Technology (ChangZhou) Corp., Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT( \
    k10, k20, k30, k40, k50, k60, k70, k80, k90, ka0, kb0, kc0, kd0, ke0, \
    k00, k11, k21, k31, k41, k51, k61, k71, k81, k91, ka1, kb1, kc1, kf0, kg0, \
    k01, k12, k22, k32, k42, k52, k62, k72, k82, k92, ka2, kb2, kd1, ke1, kf1, \
    k02, k13, k23, k33, k43, k53, k63, k73, k83, k93, ka3, kc2, kd2, kg1, \
    k03, k34, k44, k54, k64, k74, k94, ka4, kb4, kc4, kb3, ke2, kf2, \
    k04, k14, k24, k84, kd4, ke4, kc3, kd3, ke3, kg2 \
) \
{ \
    { k00, k01, k02, k03, k04}, \
    { k10, k11, k12, k13, k14}, \
    { k20, k21, k22, k23, k24}, \
    { k30, k31, k32, k33, k34}, \
    { k40, k41, k42, k43, k44}, \
    { k50, k51, k52, k53, k54}, \
    { k60, k61, k62, k63, k64}, \
    { k70, k71, k72, k73, k74}, \
    { k80, k81, k82, k83, k84}, \
    { k90, k91, k92, k93, k94}, \
    { ka0, ka1, ka2, ka3, ka4}, \
    { kb0, kb1, kb2, kb3, kb4}, \
    { kc0, kc1, kc2, kc3, kc4}, \
    { kd0, kd1, kd2, kd3, kd4}, \
    { ke0, ke1, ke2, ke3, ke4}, \
    { kf0, kf1, kf2, ___, ___}, \
    { kg0, kg1, kg2, ___, ___}  \
}
// clang-format on
