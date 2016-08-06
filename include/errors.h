/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 10:57:31 by oexall            #+#    #+#             */
/*   Updated: 2016/08/06 09:00:39 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define E_NONEXISTANT ": No such file or directory: "
# define E_INVALIDARGS ": String not in pwd: "
# define E_DENIEDACCESS ": Permission Denied: "
# define E_NOTDIR ": Not a directory: "
# define E_NOHOME ": Home Directory not Found"

# define E_MALLOC "Failed to malloc"
# define E_INVALIDVAR "No ENV with that name"
# define E_NOARGS "Not enough Arguments"
# define E_SETENVARGS "Invalid Arguments\n\tUsage: setenv [NAME] [value]"

#endif
