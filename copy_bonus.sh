cp get_next_line.h get_next_line_bonus.h
cp get_next_line.c get_next_line_bonus.c
cp get_next_line_utils.c get_next_line_utils_bonus.c
sed -i 's/GET_NEXT_LINE_H/GET_NEXT_LINE_BONUS_H/' get_next_line_bonus.h
sed -i 's/get_next_line.h/get_next_line_bonus.h/' get_next_line_bonus.c get_next_line_utils_bonus.c
