  #!/bin/bash
  #Se asigna al trabajo el nombre ejercicio10
  #PBS -N ejercicio10
  #Se asigna al trabajo la cola ac
  #PBS -q ac
  #Se imprime información del trabajo usando variables de entorno de PBS
  echo "Id. usuario del trabajo: $PBS_O_LOGNAME"
  echo "Id. del trabajo: $PBS_JOBID"
  echo "Nombre del trabajo especificado por usuario: $PBS_JOBNAME"
  echo "Nodo que ejecuta qsub: $PBS_O_HOST"
  echo "Directorio en el que se ha ejecutado qsub: $PBS_O_WORKDIR"
  echo "Cola: $PBS_QUEUE"
  echo "Nodos asignados al trabajo:"
  cat $PBS_NODEFILE

  tamanio=350

  echo -e "TAMAÑO $tamanio:"
  for ((N=1;N<25;N=N+1))
  do
    export OMP_NUM_THREADS=$N
    echo -e "\nNº hebras: $N\n"
    $PBS_O_WORKDIR/ejercicio10 $tamanio
  done
