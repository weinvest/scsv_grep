# scsv_grep
场景:  有很多个csv的第一列为key,key是有序的 key是统一生成的，每个文件的key都是一个子集，现在给定一个key要找出所有出现的行

seq_csv_grep: 一行一行地查找
bin_csv_grep: 使用内存映射 + binary search
