  #!/bin/bash
  #Se asigna al trabajo el nombre ejercicio7
  #PBS -N ejercicio7
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

  tamanio=30720

  export OMP_SCHEDULE="static"
  echo "static y chunk por defecto"
  $PBS_O_WORKDIR/ejercicio7 $tamanio

  export OMP_SCHEDULE="static,1"
  echo "static y chunk a 1"
  $PBS_O_WORKDIR/ejercicio7 $tamanio

  export OMP_SCHEDULE="static,64"
  echo "static y chunk a 64"
  $PBS_O_WORKDIR/ejercicio7 $tamanio

  export OMP_SCHEDULE="dynamic"
  echo "dynamic y chunk por defecto"
  $PBS_O_WORKDIR/ejercicio7 $tamanio

  export OMP_SCHEDULE="dynamic,1"
  echo "dynamic y chunk a 1"
  $PBS_O_WORKDIR/ejercicio7 $tamanio

  export OMP_SCHEDULE="dynamic,64"
  echo "dynamic y chunk a 64"
  $PBS_O_WORKDIR/ejercicio7 $tamanio

  export OMP_SCHEDULE="guided"
  echo "guided y chunk por defecto"
  $PBS_O_WORKDIR/ejercicio7 $tamanio

  export OMP_SCHEDULE="guided,1"
  echo "guided y chunk a 1"
  $PBS_O_WORKDIR/ejercicio7 $tamanio

  export OMP_SCHEDULE="guided,64"
  echo "guided y chunk a 64"
  $PBS_O_WORKDIR/ejercicio7 $tamanio
