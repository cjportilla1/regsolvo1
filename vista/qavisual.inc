<div class="container mt-5  ">
    <div class="container formulario1 imgs p-5">
    <h1 class="azul titulos ">REGISTROS QA</h1>
        <table id="tusuarios" class="  table-striped " width="100%" height="100%">

            <thead class=" ">
                <tr class=" text-center fverde  fsolvo text-light">
               
                    <th class="titulos">Fecha</th>
                   
                    <th class="titulos">Inter ID</th>
                    <th class="titulos">Name</th>
                    <th class="titulos">TL</th>
                    <th class="titulos">Score</th>
                    <th class="titulos">Details</th>
                  




                </tr>
            </thead>
            <tbody>


                <?php

                if (isset($_GET['eliminar'])) {

                    $sqlDelete = "call del_qareg(" . $_GET['id'] . ")";
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

                    if ($_SESSION["perf"]="supervisor") {
                       $sql="call cons_user('".$_SESSION['SOLVID']."')";

                       $exe = $createcon->query($sql);




                       while ($row = $exe->fetch_array()) {
       
                          
                           echo "<tr class='text-center texto ' >
                             
                              
                                   <td>" . $row[1] . "</td>
                                   <td>" . $row[2] . "</td>
                                
                                  
                                   <td>" . $row[3] . "</td>
                                   <td>" . $row[4] . "</td>
                                   <td>" . $row[5] . "</td>
                                   <td> <button type='button' class='btn btn-primary' data-toggle='modal' data-target='#exampleModalLong".$row[0]."'>
                                   Detalles de calificacion
                                 </button>
       
                                 <!-- Modal -->
                                 <div class='modal fade' id='exampleModalLong".$row[0]."' tabindex='-1' role='dialog' aria-labelledby='exampleModalLongTitle' aria-hidden='true'>
                                   <div class='modal-dialog' role='document'>
                                     <div class='modal-content'>
                                       <div class='modal-header'>
                                         <h5 class='modal-title' id='exampleModalLongTitle'>Detalles de la calificacion</h5>
                                         <button type='button' class='close' data-dismiss='modal' aria-label='Close'>
                                           <span aria-hidden='true'>&times;</span>
                                         </button>
                                       </div>
                                       <div class='modal-body'>
                                       <textarea  class='form-control'  placeholder='Detalles' > ".$row[6]."  </textarea>   
                                 
                                          
                                                    
                                 
                                       </div>
                                       <div class='modal-footer'>
                                         <button type='button' class='btn btn-secondary' data-dismiss='modal'>Close</button>
                                       
                                       </div>
                                     </div>
                                   </div>
                                 </div>
                                 
                                 
                                 
                                 
                                 
                                 </td>
                                 </tr>
                                 
                                
                                   ";
                       
                       }

                    }elseif ($_SESSION["perf"]="colaborador") {
                        
                        $sql="call mostqa_reg";

                        $exe = $createcon->query($sql);
 
 
 
 
                        while ($row = $exe->fetch_array()) {
        
                           
                            echo "<tr class='text-center texto ' >
                              
                               
                                    <td>" . $row[1] . "</td>
                                    <td>" . $row[2] . "</td>
                                 
                                   
                                    <td>" . $row[3] . "</td>
                                    <td>" . $row[4] . "</td>
                                    <td>" . $row[5] . "</td>
                                    <td> <button type='button' class='btn btn-primary' data-toggle='modal' data-target='#exampleModalLong".$row[0]."'>
                                    Detalles de calificacion
                                  </button>
        
                                  <!-- Modal -->
                                  <div class='modal fade' id='exampleModalLong".$row[0]."' tabindex='-1' role='dialog' aria-labelledby='exampleModalLongTitle' aria-hidden='true'>
                                    <div class='modal-dialog' role='document'>
                                      <div class='modal-content'>
                                        <div class='modal-header'>
                                          <h5 class='modal-title' id='exampleModalLongTitle'>Detalles de la calificacion</h5>
                                          <button type='button' class='close' data-dismiss='modal' aria-label='Close'>
                                            <span aria-hidden='true'>&times;</span>
                                          </button>
                                        </div>
                                        <div class='modal-body'>
                                        <textarea  class='form-control'  placeholder='Detalles' > ".$row[6]."  </textarea>   
                                  
                                           
                                                     
                                  
                                        </div>
                                        <div class='modal-footer'>
                                          <button type='button' class='btn btn-secondary' data-dismiss='modal'>Close</button>
                                        
                                        </div>
                                      </div>
                                    </div>
                                  </div>
                                  
                                  
                                  
                                  
                                  
                                  </td>
                                  </tr>
                                  
                                 
                                    ";
                        
                        }
                        # code...
                    }
                      
           


               



                ?>

                
               


    </div>


    </tbody>


    </table>
 
    
    <div class="form-row-12">
        <div class="col">
        <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesión</a> </mark>
        </div>
         
         
        </div>

</div>