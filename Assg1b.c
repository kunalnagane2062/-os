#!/bin/bash
filename=""
create()
{
echo -e "Create..."
echo -e "\n Enter the name of the file :\c"
read filename
len=$(echo -n $filename | wc -m)
if test $len -gt 0;then
if [ -f "$filename" ]; then
 echo "$filename exists."
else 
 echo "$filename does not exist.Creating it..."
 touch $filename
 echo "File with name $filename created successfully."
fi
else 
echo "\n Filename cannot be empty."
fi
}
readf()
{
echo -e "read..."
cat $filename
}
insertinto()
{
echo -e "insert.."
echo -e "Enter your roll number:"
read r_no
echo -n $r_no >> $filename
echo -n " " >> $filename
echo -e "Enter your name:"
read name
echo -n $name >> $filename
echo -n " " >> $filename
echo -e "Enter your department:"
read d_name
echo -n $d_name >> $filename
echo -n " " >> $filename
echo -e "Enter your phone number:"
read p_no
echo -n $p_no >> $filename
echo -n " " >> $filename
echo -e "" >> $filename
}
deletefrom()
{
echo "delete..."
echo -e "Enter your roll number:"
read r_no
sed -i "/$r_no/d" $filename
}
modify()
{
echo "modify..."
echo -e "Enter your id:"
read r_no
if ( grep -q $r_no $filename )
then
 echo "Enter the name:"
 read name
 echo "Enter the department:"
 read dept
 echo "Enter the phone number:"
 read p_no
 sed -i "/$r_no/c\ $r_no\ $name\ $dept\ $p_no" $filename
else
 echo "Your record not found."
fi
}
search()
{
echo "Search..."
echo -e "Enter your id:"
read r_no
if ( grep -q $r_no $filename )
then
 echo "Search Successfull..." 
else
 echo "Search Unsuccessfull..."
fi
}
flag=0
while [ flag==0 ]
do
echo -e "\nEnter your choice : \c"
echo -e "\n1.Create DB: \c"
echo -e "\n2.Read DB : \c"
echo -e "\n3.Insert DB : \c"
echo -e "\n4:Delete DB: \c"
echo -e "\n5:Modify: \c"
echo -e "\n6:Search: \c"
echo -e "\n7:exit DB: \c"
read x
case $x in
1 )
create
;;
2 )
readf
;;
3 )
insertinto
;;
4 )
deletefrom
;;
5 )
modify
;;
6 )
search
;;
7 )
echo "exit..." 
break ;;
esac
don
