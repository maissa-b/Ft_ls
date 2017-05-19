/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 17:28:32 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/05 17:46:46 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char				*get_perm(t_dir *dir, char *str)
{
	char			*perm;

	perm = ft_strnew(12);
	perm[0] = check_type_file(dir);
	perm[1] = ((dir->sb.st_mode & S_IRUSR) ? 'r' : '-');
	perm[2] = ((dir->sb.st_mode & S_IWUSR) ? 'w' : '-');
	perm[3] = check_uid_bit(dir);
	perm[4] = ((dir->sb.st_mode & S_IRGRP) ? 'r' : '-');
	perm[5] = ((dir->sb.st_mode & S_IWGRP) ? 'w' : '-');
	perm[6] = check_gid_bit(dir);
	perm[7] = ((dir->sb.st_mode & S_IROTH) ? 'r' : '-');
	perm[8] = ((dir->sb.st_mode & S_IWOTH) ? 'w' : '-');
	perm[9] = check_sticky_bit(dir);
	perm[10] = get_extented_attributes(str);
	return (perm);
}

void				put_symblnk(char *str, t_dir *dir)
{
	char			*arrow;
	char			*tmp;
	char			*tmp2;
	struct stat		stats;
	ssize_t			read;

	arrow = ft_strdup(" -> ");
	tmp = NULL;
	tmp2 = NULL;
	read = 0;
	(void)dir;
	if (str && (tmp2 = (char*)malloc(sizeof(char) * 2048)))
	{
		lstat(str, &stats);
		if ((read = readlink(str, tmp2, 2047)))
			tmp2[read] = '\0';
		if (S_ISLNK(stats.st_mode))
		{
			tmp = ft_multijoin(tmp, str, arrow, tmp2);
		}
		ft_putendl(tmp);
		ft_multifruee(&tmp, &tmp2, &arrow);
	}
}

void				put_symblnk_dir(char *str, t_dir *dir)
{
	char			*arrow;
	char			*tmp;
	char			*tmp2;
	struct stat		stats;
	ssize_t			read;

	arrow = ft_strdup(" -> ");
	tmp = NULL;
	tmp2 = NULL;
	read = 0;
	(void)dir;
	if (str && (tmp2 = (char*)malloc(sizeof(char) * 2047)))
	{
		lstat(str, &stats);
		if ((read = readlink(str, tmp2, 2048)))
			tmp2[read] = '\0';
		if (S_ISLNK(stats.st_mode))
			tmp = ft_multijoin(tmp, ft_strrchr(str, '/') + 1, arrow, tmp2);
		else
			tmp = ft_multijoin(tmp, str, arrow, tmp2);
		ft_putendl(tmp);
		ft_multifruee(&tmp, &tmp2, &arrow);
	}
}

void				opt_l_files(t_data *da, t_opt *opt, t_dir *dir)
{
	if (!da || !da->arg)
		return ;
	aff_aft_str((dir->max_rights + 1), ft_strlen(da->rights), da->rights);
	aff_bef_nbr(dir->max_hlnk, ft_intlen(da->n_hlnk), da->n_hlnk);
	write(1, " ", 1);
	(!opt->g) ? aff_aft_str(dir->max_uid, ft_strlen(da->uid), da->uid) : 0;
	(opt->g || opt->o) ? 0 : write(1, "  ", 2);
	(!opt->o) ? aff_aft_str(dir->max_gid, ft_strlen(da->gid), da->gid) : 0;
	if (da->rights[0] == 'b' || da->rights[0] == 'c')
		print_minor_major(dir, da->minor, da->major);
	else
		aff_bef_nbr((dir->max_bytes + 2), ft_intlen(da->bytes), da->bytes);
	write(1, " ", 1);
	dir->date = parse_time(opt, dir, da->timer);
	if ((dir->date = parse_time(opt, dir, da->timer)))
		aff_aft_str(dir->max_date + 1, ft_strlen(da->date), dir->date);
	(da->rights[0] == 'l') ? put_symblnk(da->arg, dir) : ft_putendl(da->arg);
	ft_strdel(&(dir->date));
}

void				opt_l_dir(t_argf *af, t_data *da, t_opt *opt, t_dir *dir)
{
	aff_aft_str((dir->max_rights + 1), ft_strlen(da->rights), da->rights);
	aff_bef_nbr(dir->max_hlnk, ft_intlen(da->n_hlnk), da->n_hlnk);
	write(1, " ", 1);
	(!opt->g) ? aff_aft_str(dir->max_uid, ft_strlen(da->uid), da->uid) : 0;
	(opt->g || opt->o) ? 0 : write(1, "  ", 2);
	(!opt->o) ? aff_aft_str(dir->max_gid, ft_strlen(da->gid), da->gid) : 0;
	if (da->rights[0] == 'b' || da->rights[0] == 'c')
		print_minor_major(dir, da->minor, da->major);
	else
	{
		if (af->prev && (af->prev->data->rights[0] == 'b' || \
			af->prev->data->rights[0] == 'c'))
		{
			aff_bef_nbr((dir->max_minor + dir->max_major + dir->max_bytes) \
				+ 5, ft_intlen(da->bytes), da->bytes);
		}
		else
			aff_bef_nbr(dir->max_bytes + 2, ft_intlen(da->bytes), da->bytes);
	}
	write(1, " ", 1);
	if ((dir->date = parse_time(opt, dir, da->timer)))
		aff_aft_str(dir->max_date + 1, ft_strlen(da->date), dir->date);
	(da->rights[0] == 'l') ? put_symblnk_dir(da->arg, dir) : is_opt_p(af, opt);
	ft_strdel(&(dir->date));
}
