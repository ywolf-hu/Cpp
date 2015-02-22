for x in *; do 
#  if ! [ -x $x ]; then continue; fi;
   tmp="${x}"
   if [ "${tmp#*.}" != "exe" ]; then continue; fi
   echo '<<' $x '>>';  
  ./$x; 
done;
