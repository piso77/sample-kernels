/*
 * AppArmor security module
 *
 * This file contains AppArmor file mediation function definitions.
 *
 * Copyright 2014 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 2 of the
 * License.
 *
 *
 * This is a file of helper macros, defines for backporting newer versions
 * of apparmor to older kernels
 */
#ifndef __AA_BACKPORT_H
#define __AA_BACKPORT_H

#include <linux/fs.h>

/* 4.4 backport to supprt 5955102c9984fa081b2d570cfac75c97eecf8f3b */
static inline void inode_lock(struct inode *inode)
{
	mutex_lock(&inode->i_mutex);
}

static inline void inode_unlock(struct inode *inode)
{
	mutex_unlock(&inode->i_mutex);
}

static inline void inode_lock_nested(struct inode *inode, unsigned subclass)
{
	mutex_lock_nested(&inode->i_mutex, subclass);
}

#endif /* __AA_BACKPORT_H */
