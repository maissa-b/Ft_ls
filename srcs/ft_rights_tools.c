/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rights_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:27:14 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/05 18:04:30 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char			check_uid_bit(t_dir *dir)
{
	char		c;

	if (dir->sb.st_mode & S_ISUID)
		c = (dir->sb.st_mode & S_IXUSR) ? 's' : 'S';
	else
		c = (dir->sb.st_mode & S_IXUSR) ? 'x' : '-';
	return (c);
}

char			check_gid_bit(t_dir *dir)
{
	char		c;

	if (dir->sb.st_mode & S_ISGID)
		c = (dir->sb.st_mode & S_IXGRP) ? 's' : 'S';
	else
		c = ((dir->sb.st_mode & S_IXGRP) ? 'x' : '-');
	return (c);
}

char			check_sticky_bit(t_dir *dir)
{
	char		c;

	if (dir->sb.st_mode & S_ISVTX)
		c = (dir->sb.st_mode & S_IXOTH) ? 't' : 'T';
	else
		c = ((dir->sb.st_mode & S_IXOTH) ? 'x' : '-');
	return (c);
}

char			get_extented_attributes(char *str)
{
	acl_t		acl;
	char		*buff;

	buff = NULL;
	acl = NULL;
	if ((listxattr(str, buff, 256, XATTR_NOFOLLOW)) > 0)
	{
		return ('@');
	}
	if ((acl = acl_get_file(str, ACL_TYPE_EXTENDED)))
	{
		free(acl);
		return ('+');
	}
	return (' ');
}

char			check_type_file(t_dir *dir)
{
	char		c;

	c = '\0';
	if (S_ISBLK(dir->sb.st_mode))
		c = 'b';
	else if (S_ISCHR(dir->sb.st_mode))
		c = 'c';
	else if (S_ISDIR(dir->sb.st_mode))
		c = 'd';
	else if (S_ISLNK(dir->sb.st_mode))
		c = 'l';
	else if (S_ISSOCK(dir->sb.st_mode))
		c = 's';
	else if (S_ISFIFO(dir->sb.st_mode))
		c = 'p';
	else if (S_ISWHT(dir->sb.st_mode))
		c = 'w';
	else if (S_ISREG(dir->sb.st_mode))
		c = '-';
	return (c);
}
