/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousecode_macos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:11:05 by hsim              #+#    #+#             */
/*   Updated: 2025/01/10 13:19:42 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSECODE_MACOS_H
# define MOUSECODE_MACOS_H

/* ------------------------------- clicks -------------------------------- */
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3

/* ------------------------------ scrolls -------------------------------- */
# define UP_SCROLL 5
# define DOWN_SCROLL 4

/* -------------------------- mlx X11 events ----------------------------- */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6

/* ------------------------ mlx X11 event mask ---------------------------
# define KEYPRESSMASK 1L << 0
# define KEYRELEASEMASK 1L << 1
# define BUTTONMOTIONMASK 1L << 13
# define BUTTONPRESSMASK 1L << 2
# define BUTTONRELEASEMASK 1L << 3
# define BUTTON1MOTIONMASK 1L << 8
# define BUTTON4MOTIONMASK 1L << 11
# define BUTTON5MOTIONMASK 1L << 12
# define POINTERMOTIONMASK 1L << 6
*/

#endif