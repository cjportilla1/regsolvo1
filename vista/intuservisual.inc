<div class="container mt-5  ">
    <div class="container formulario1 imgs p-5">
        <table id="tusuarios" class="  table-striped " width="100%" height="100%">

            <thead class=" ">
                <tr class=" text-center fverde  fsolvo text-light">
                  
              
                    <th class="titulos">Nombre</th>
                    <th class="titulos">Apellido</th>
                    <th class="titulos">Mail</th>
                    <th class="titulos">Pass</th>
                    <th class="titulos">Rol</th>
                    <th class="titulos">Sol ID</th>
                    <th class="titulos">Last login</th>



                </tr>
            </thead>
            <tbody>

            <?php

if (isset($_GET['eliminar'])) {

    $sqlDelete = "call del_us(" . $_GET['id'] . ")";
    $res = $createcon->query($sqlDelete);


    // while ($fila = $res->fetch_array()) {
    $fila = $res->fetch_row();

    // print_r($fila);

    // if ($row[0]=1) {
    //     echo "<label class='text-danger' >usuario eliminado correctamente</label>";
    // } else {
    //     echo "<label class='text-danger' >usuario admin,no se puede eliminar</label>";
    // }
    // }
}


$sql = "call sho_usernoadmin('".$_SESSION['usuar']."')";


$exe = $createcon->query($sql);




while ($row = $exe->fetch_array()) {

  switch ($row[5]) {
      case '1': $showrol="Administrador";
          # code...
          break;
          case '2': $showrol="Supervisor";
          # code...
          break;
          case '3': $showrol="Colaborador";
          # code...
          break;
          case '4': $showrol="Practicante IT";
          # code...
          break;
      
      default:
         $showrol="visual";
          break;
  }
    echo "<tr class='text-center texto ' >
        
       
            <td>" . $row[1] . "</td>
            <td>" . $row[2] . "</td>
         
           
            <td>" . $row[3] . "</td>
            <td>" . $row[4] . "</td>
            <td>" . $showrol . "</td>
            <td>" . $row[6] . "</td>
            <td>" . $row[7] . "</td>
         
            </tr>";
}




?>

    </div>


    </tbody>


    </table>
</div>