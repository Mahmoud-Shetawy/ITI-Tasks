<?php


$user = $_POST;


// var_dump( $user );

function register($user){
    echo "<table border=2>";
    echo "<tr>";
    $allowed_keys = ["name","email", "password"];
    foreach($user as $key => $value){
        if (in_array($key, $allowed_keys)) { 
           echo "<th>$key</th>";
        }
    };
    echo "</tr>";
    echo "<tr>";
    foreach($user as $key => $value){
        if (in_array($key, $allowed_keys)) { 
     echo "<td>$value</td>";
        }
    
    };
    echo "</tr>";
    echo "</table>";
}


function login($user)
{

    echo "<table border=2 style='margin-top:300px; margin-left:500px;background-color:wheat'>";
    echo "<tr>";
    $allowed_keys = ["email", "password"];
    foreach($user as $key => $value){
        if (in_array($key, $allowed_keys)) { 
            echo "<th>$key</th>";
        }
        
    };
    echo "</tr>";
    echo "<tr>";
    foreach($user as $key => $value){
        if (in_array($key, $allowed_keys)) { 
            echo "<td>$value</td>";   
        }

    
    };
    echo "</tr>";
    echo "</table>";
}

if($user["action"]==="register"){
    
    register($user);
}
if($user["action"]=== "login"){
    login($user);
}










?>