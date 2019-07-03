#!/bin/sh

clear
make -s

i=0
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n direct_param_no_value\n"
     ./asm vm_champs/error/direct_param_no_value.s
./vm_champs/asm vm_champs/error/direct_param_no_value.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n op_double_operation_on_single_line\n"
     ./asm vm_champs/error/op_double_operation_on_single_line.s
./vm_champs/asm vm_champs/error/op_double_operation_on_single_line.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n comment_len_2049\n"
     ./asm vm_champs/error/comment_len_2049.s
./vm_champs/asm vm_champs/error/comment_len_2049.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))


echo "\n four_arg_malloc_free_pointer_error\n"
     ./asm vm_champs/error/four_arg_malloc_free_pointer_error.s
./vm_champs/asm vm_champs/error/four_arg_malloc_free_pointer_error.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n header_double_comments\n"
     ./asm vm_champs/error/header_double_comments.s
./vm_champs/asm vm_champs/error/header_double_comments.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n header_double_names\n"
     ./asm vm_champs/error/header_double_names.s
./vm_champs/asm vm_champs/error/header_double_names.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n header_max_comment\n"
     ./asm vm_champs/error/header_max_comment.s
./vm_champs/asm vm_champs/error/header_max_comment.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n header_nl_unclosed\n"
     ./asm vm_champs/error/header_nl_unclosed.s
./vm_champs/asm vm_champs/error/header_nl_unclosed.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n header_nl\n"
     ./asm vm_champs/error/header_nl.s
./vm_champs/asm vm_champs/error/header_nl.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n header_null_name\n"
     ./asm vm_champs/error/header_null_name.s
./vm_champs/asm vm_champs/error/header_null_name.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n label_contain_badchar\n"
     ./asm vm_champs/error/label_contain_badchar.s
./vm_champs/asm vm_champs/error/label_contain_badchar.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n label_error_1\n"
     ./asm vm_champs/error/label_error_1.s
./vm_champs/asm vm_champs/error/label_error_1.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n label_error_2\n"
     ./asm vm_champs/error/label_error_2.s
./vm_champs/asm vm_champs/error/label_error_2.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n label_error_3\n"
     ./asm vm_champs/error/label_error_3.s
./vm_champs/asm vm_champs/error/label_error_3.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n label_invalidname\n"
     ./asm vm_champs/error/label_invalidname.s
./vm_champs/asm vm_champs/error/label_invalidname.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n label_noending\n"
     ./asm vm_champs/error/label_noending.s
./vm_champs/asm vm_champs/error/label_noending.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n label_space\n"
     ./asm vm_champs/error/label_space.s
./vm_champs/asm vm_champs/error/label_space.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n label_without_double_dot_at_the_end\n"
     ./asm vm_champs/error/label_without_double_dot_at_the_end.s
./vm_champs/asm vm_champs/error/label_without_double_dot_at_the_end.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n name_len_129\n"
     ./asm vm_champs/error/name_len_129.s
./vm_champs/asm vm_champs/error/name_len_129.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n op_extra\n"
     ./asm vm_champs/error/op_extra.s
./vm_champs/asm vm_champs/error/op_extra.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n op_extreme\n"
     ./asm vm_champs/error/op_extreme.s
./vm_champs/asm vm_champs/error/op_extreme.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n op_no_code\n"
     ./asm vm_champs/error/op_no_code.s
./vm_champs/asm vm_champs/error/op_no_code.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_badtypes\n"
     ./asm vm_champs/error/param_badtypes.s
./vm_champs/asm vm_champs/error/param_badtypes.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_commas\n"
     ./asm vm_champs/error/param_commas.s
./vm_champs/asm vm_champs/error/param_commas.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_direct_no_sp\n"
     ./asm vm_champs/error/param_direct_no_sp.s
./vm_champs/asm vm_champs/error/param_direct_no_sp.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_direct_no_value\n"
     ./asm vm_champs/error/param_direct_no_value.s
./vm_champs/asm vm_champs/error/param_direct_no_value.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_double_commas\n"
     ./asm vm_champs/error/param_double_commas.s
./vm_champs/asm vm_champs/error/param_double_commas.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_extra2\n"
     ./asm vm_champs/error/param_extra2.s
./vm_champs/asm vm_champs/error/param_extra2.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_mt_3\n"
     ./asm vm_champs/error/param_mt_3.s
./vm_champs/asm vm_champs/error/param_mt_3.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_mt_r99\n"
     ./asm vm_champs/error/param_mt_r99.s
./vm_champs/asm vm_champs/error/param_mt_r99.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_nonexistent_label\n"
     ./asm vm_champs/error/param_nonexistent_label.s
./vm_champs/asm vm_champs/error/param_nonexistent_label.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_plus_minus\n"
     ./asm vm_champs/error/param_plus_minus.s
./vm_champs/asm vm_champs/error/param_plus_minus.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n param_specialchars\n"
     ./asm vm_champs/error/param_specialchars.s
./vm_champs/asm vm_champs/error/param_specialchars.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n zother_1\n"
     ./asm vm_champs/error/zother_1.s
./vm_champs/asm vm_champs/error/zother_1.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n zother_2\n"
     ./asm vm_champs/error/zother_2.s
./vm_champs/asm vm_champs/error/zother_2.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n zother_3\n"
     ./asm vm_champs/error/zother_3.s
./vm_champs/asm vm_champs/error/zother_3.s

read -p "Appuez sur une touche pour continuer... "
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n zother_4\n"
     ./asm vm_champs/error/zother_4.s
./vm_champs/asm vm_champs/error/zother_4.s

rm -rf notre vrai