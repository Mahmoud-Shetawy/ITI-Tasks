<?php

$user = [
    "id"=>1,
    "name"=> "ali",
    "email"=> "ali@gmail.com",
    "age"=>25,
    "country"=>"EGY"
];


foreach( $user as $key => $value ) {
    echo"==". $key ."==". $value ."<br>";
};

unset( $user['country'] );
echo "=========================================<br>";
foreach( $user as $key => $value ) {
    echo"==". $key ."==". $value ."<br>";
};


$users = [

    ["id"=> 1,"name"=> "ali","email"=> "ali@g,ail.com","Country"=>"Egy"],
    ["id"=> 2,"name"=> "adel","email"=> "adel@g,ail.com","Country"=>"san"],
    ["id"=> 3,"name"=> "mostafa","email"=> "mostafa@g,ail.com","Country"=>"sultan"],
    ["id"=> 4,"name"=> "zeyad","email"=> "zeyad@g,ail.com","Country"=>"Barhim"],
    ["id"=> 5,"name"=> "mohamed","email"=> "mohamed@g,ail.com","Country"=>"Egy"]
];

echo "<table border=2 style='background-color:wheat; color:black; margin-left:500px'>";
echo "<tr>";
foreach( $users[0] as $key => $value ) {
    echo "<th>$key</th>";
};
echo"</tr>";

foreach( $users as  $user ) {
   echo "<tr>";
   foreach( $user as  $value ) {
      echo "<td>$value</td>";
   };
   echo"</tr>";
}

echo "</table>";




?>