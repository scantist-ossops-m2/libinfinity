/* infinote - Collaborative notetaking application
 * Copyright (C) 2007 Armin Burgmeier
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __INF_ADOPTED_STATE_VECTOR_H__
#define __INF_ADOPTED_STATE_VECTOR_H__

#include <libinfinity/common/inf-user.h>

#include <glib-object.h>

G_BEGIN_DECLS

#define INF_ADOPTED_TYPE_STATE_VECTOR            (inf_adopted_state_vector_get_type())

/* TODO: Wrap in own struct for type safety? However, StateVectors are often
 * used and I think it is best if they are as fast as possible. */
/* TODO: Only store user ID instead of user object? */
/* TODO: I think GTree is better suited for what we are looking, but it does
 * not allow iteration over its elements, required for
 * inf_adopted_state_vector_compare. */
typedef GSequence InfAdoptedStateVector;

typedef void(*InfAdoptedStateVectorForeachFunc)(InfUser*, guint, gpointer);

GType
inf_adopted_state_vector_get_type(void) G_GNUC_CONST;

InfAdoptedStateVector*
inf_adopted_state_vector_new(void);

InfAdoptedStateVector*
inf_adopted_state_vector_copy(InfAdoptedStateVector* vec);

void
inf_adopted_state_vector_free(InfAdoptedStateVector* vec);

guint
inf_adopted_state_vector_get(InfAdoptedStateVector* vec,
                             InfUser* component);

void
inf_adopted_state_vector_set(InfAdoptedStateVector* vec,
                             InfUser* component,
                             guint value);

void
inf_adopted_state_vector_add(InfAdoptedStateVector* vec,
                             InfUser* component,
                             gint value);

void
inf_adopted_state_vector_foreach(InfAdoptedStateVector* vec,
                                 InfAdoptedStateVectorForeachFunc func,
                                 gpointer user_data);

int
inf_adopted_state_vector_compare(InfAdoptedStateVector* first,
                                 InfAdoptedStateVector* second);

gboolean
inf_adopted_state_vector_causally_before(InfAdoptedStateVector* first,
                                         InfAdoptedStateVector* second);

G_END_DECLS

#endif /* __INF_ADOPTED_STATE_VECTOR_H__ */
