<div class="container text-center imgs mt-2  formulario1 p-5 col-10">


    <h1 class="azul titulos ">REGISTROS QA</h1>









    <form class="" action="" method="POST" id="formRegistroUser" ectype="multipart/form-data">


        <div class="form-row">
            <div class="form-group col">
                <label for=""><span class="font-weight-bold titulos">FECHA</span></label>
                <input type="datetime-local" name="qatimefe" max="<?php  echo date("Y-m-d\TH:i" );?>" value="<?php    if (!isset($_POST["fechareg"])) {

                                echo "2020-01-01T00:00";
                                # code...
                            }
                            else {
                          $exampleDate = $_POST["fechareg"];
                        $exampleDate = strtotime($exampleDate);
                        $newDate = date('Y-m-d\TH:i', $exampleDate);

                        echo $newDate;
                            } ?>" class="form-control" placeholder="Fecha registro"/>
            </div>

            <div class="form-group col">
                <label for=""><span class="font-weight-bold titulos">Interpreter ID</span></label>
                <input name="interpidfe" type="text" class="form-control" id="apellid" placeholder="ID del interprete"  value="<?php echo $_POST["interpid"]; ?>">
            </div>



        </div>

        <div class="form-row">

        <div class=" form-group col">
                <label for=""><span class="font-weight-bold titulos">Nombre</span></label>
                <input name="nameinterp" type="text" class="form-control" id="nombreid" placeholder="Nombre del interprete"  value="<?php echo $_POST["interpname"]; ?>">
            </div>


            <div class="form-group col">

                <label for="inputca"><span class="font-weight-bold">TL</span></label>

                <select name="tlname" id="inputcargo" class="form-control">
                    <option value="" disabled> </option>
                    <?php
                    if (empty($_POST["tlnomb"])) {

                        echo "<option value=''> seleccione--> ";
                     echo  " <option value='Alfredo Eusse'>Alfredo Eusse</option>";
                     echo "   <option value='Jose Sevillano'>Jose Sevillano</option>";
                     echo "   <option value='Sebastian Sanchez'>Sebastian Sanchez</option>";
                     echo " <option value='Silvino Navarro'>Silvino Navarro</option>";
                    
                    
                    }else {
                        echo " <option value='".$_POST['tlnomb']."'>".$_POST['tlnomb']."</option>";
                        echo  " <option value='Alfredo Eusse'>Alfredo Eusse</option>";
                        echo "   <option value='Jose Sevillano'>Jose Sevillano</option>";
                        echo "   <option value='Sebastian Sanchez'>Sebastian Sanchez</option>";
                        echo " <option value='Silvino Navarro'>Silvino Navarro</option>";
                   
                   
                    }
                    ?>

                  

                </select>
            </div>




        </div>

        <div class="form-row">

        <label for=""><span class="font-weight-bold titulos">Calificacion</span></label>
                <input name="numcal" type="number" class="form-control" id="nombreid"  min="0" max="100" placeholder="total calificacion"  value="<?php echo $_POST["scoreqar"]; ?>">

        </div>

        <div class="form-row">


         
        
             <div class=" from-group col">
                <label for=""><span class="font-weight-bold titulos">Detalles</span></label>
                <textarea name="detallesqa" class="form-control" id="nombreid" placeholder="Detalles"  value="" ><?php echo $_POST["comenta"]; ?> </textarea>
            </div>

        </div>








        <div class="form-row">


            <div class="col">

                <button type="button" onclick="cruduserit('saveqareg')" class="btn btn-verde text-light">
                    REGISTRAR </button> <br>
                <br>



            </div>
            <div class="col">
                <button type="button" onclick="resetform()" class="btn btn-verde text-light titulos" id="btnform">
                    Limpiar formulario </button> <br>

            </div>
            <div class="col">

                <button type="button" onclick="cruduserit('upqareg')" class="btn btn-verde text-light">
                    ACTUALIZAR </button> <br>

                <article id="alerta" class="alert-warning text-danger"></article>

            </div>


      

        </div>

        <div class="form-row-12">
            <mark> <a href="cerrarsesion.php" class="text-danger btn btn-warning">Cerrar sesión</a> </mark>
            <?php

            if (empty($_POST["idqaregis"])) {
                echo '<input type="hidden" name="idqaregis" value="0">';

                # code...
            } elseif (!empty($_POST["idqaregis"])) {
                echo '<input type="hidden" name="idqaregis" value="' . $_POST["idqaregis"] . '">';
                # code...
            }
            ?>
        </div>


    </form>








</div>




<div class="container mt-5  ">
    <div class="container formulario1 imgs p-5">
      

           


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


                if ($_SESSION["perf"]=="supervisor"||$_SESSION["perf"]=="colaborador") {

                    $sql="call cons_user('".$_SESSION['solvid']."')";

                    $exe = $createcon->query($sql);

                    while ($row = $exe->fetch_array()) {

                    echo "
                    <table id='tusuarios' class='  table-striped ' width='100%' height='100%'>
                    
                    <thead class=' '>
                    <tr class=' text-center fverde  fsolvo text-light'>
                  
                        <th class='titulos'>Fecha</th>
                       
                        <th class='titulos'>Inter ID</th>
                        <th class='titulos'>Name</th>
                        <th class='titulos'>TL</th>
                        <th class='titulos'>Score</th>
                        <th class='titulos'>Details</th>
                        <th class='titulos'>Correo</th>
                      
    
    
    
    
                    </tr>
                </thead>
                <tbody><tr class='text-center texto ' >
                              
                               
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
                  </div>


                  </tbody>
              
              
                  </table>
                  
                 
                    ";
                    }
                 }else {
                     # code...
                     $sql = "call mostqa_reg";

                     $exe = $createcon->query($sql);




                     while ($row = $exe->fetch_array()) {
     
                        
                         echo "
                         
                         <table id='tusuarios' class='  table-striped ' width='100%' height='100%'>
                    
                         <thead class=' '>
                         <tr class=' text-center fverde  fsolvo text-light'>
                       
                             <th class='titulos'>Fecha</th>
                            
                             <th class='titulos'>Inter ID</th>
                             <th class='titulos'>Name</th>
                             <th class='titulos'>TL</th>
                             <th class='titulos'>Score</th>
                             <th class='titulos'>Details</th>
                             <th class='titulos'>Correo</th>
                           
         
         
         
         
                         </tr>
                     </thead>
                     <tbody><tr class='text-center texto ' >
                             <td>  <a href='#' class='btn btn-rojo btn-sm fsolvo' onclick='confirmDeleteqareg(" . $row[0] . ");'>Eliminar</button></td>
                             <td>
                             <form action='' method='POST'>
                             <input type='hidden' name='idqaregis' value='" . $row[0] . "'>
                             <input type='hidden' name='fechareg' value='" . $row[1] . "'>
                            <input type='hidden' name='interpid' value='" . $row[2] . "'>
                            <input type='hidden' name='interpname' value='" . $row[3] . "'>
                            <input type='hidden' name='tlnomb' value='" . $row[4] . "'>
                            <input type='hidden' name='scoreqar' value='" . $row[5] . "'>
                            <input type='hidden' name='comenta' value='" . $row[6] . "'>
                            
                        
     
                            <input class='btn btn-verde btn-sm fsolvo' type='submit'  value='Editar/act' name='accion'>
                            </form>
                         
                            </td>
                            
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
                               </div>


                               </tbody>
                           
                           
                               </table>
                               
                              
                                 ";
                     
                     }
                 }


              



                ?>

                
               


   
 
    

</div>