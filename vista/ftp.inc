<nav class="navbar navbar-expand-lg navbar-light ">

    <div class="container-fluid">

        <button type="button" id="sidebarCollapse" class="btn btn-info">
            <i class="fas fa-align-left"></i>
            <span>Menú</span>
        </button>

    </div>

</nav>

<div class="container-fluid mt-5 col-10 formulario1 imgs  p-4 ">

  <h1 class="verde titulos ">MEDIDORES</h1>
    

  <div class="card border-success mb-3" style="max-width: 18rem;">
  <div class="card-header">Medidor Bbogotá</div>
  <div class="card-body text-success">
    <h5 class="card-title">Medidor 1</h5>
    <iframe width="100%" height="25%" frameborder="0" src="https://stem.ubidots.com/app/dashboards/public/widget/05nYtxvGKqzZHElF923N40EwodIzHlYyHPyFX02aV4M?embed=true"></iframe>
  </div>
</div>
        

  

                <?php

require '../vendor/autoload.php';

$api = new Ubidots\ApiClient($apikey="BBFF-69ab7221bfff15917dcdd747415baf98323");


                    $directorio1='D:/ftp/ecc38a6001ba';
                    $archiv=scandir($directorio1,SCANDIR_SORT_DESCENDING);
                    $conv=strval($archiv[0]);
                    $ubi=($directorio1.'/'.$conv);
                  
                   

                
                   $vec=fopen($ubi,'r');    
                    $file=array_map("str_getcsv",file($ubi));

               
                    $ubidata=$file[1][91];
           

                    fclose($vec);

                    $acutest = $api->get_variable('5fc90c091d84723196179dce');
                 
                    $new_value = $acutest->save_value( json_encode(array('value'=>$ubidata)) );

           

                ?>




          


    
        
   
</div>