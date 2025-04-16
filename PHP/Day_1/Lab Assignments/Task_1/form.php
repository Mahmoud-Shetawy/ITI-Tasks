

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration</title>
    <style>
       
        label, input, select, textarea { 
        display: block; margin-bottom: 10px; width: 100%;
         }
        input[type='radio'], input[type='checkbox'] {
         width: auto; display: inline; 
         }
        }
    </style>
</head>
<body>

<h2>Registration</h2>
<form action="sever.php" method="post">

    <label>First Name:</label>
    <input type="text" name="first_name" >

    <label>Last Name:</label>
    <input type="text" name="last_name" >

    <label>Address:</label>
    <textarea name="address" rows="4"></textarea>


<!-- ------------------------------------------------------------------------- -->
    <label>Country:</label>
    <select name="country">
        <option>Select City</option>
        <option value="US">Shebeen </option>
        <option value="UK">shobraBass</option>
        <option value="IN">Kafr elme</option>
        <option value="EG">Egypt</option>
    </select>


    <label>Gender:</label>
    <input type="radio" name="gender" value="Male"> Male
    <input type="radio" name="gender" value="Female"> Female

<!-- ------------------------------------------------------------------------- -->
    <label>Skills:</label>
    <input type="checkbox" name="skills[]" value="PHP"> PHP
    <input type="checkbox" name="skills[]" value="MySQL" checked> MySQL
    <input type="checkbox" name="skills[]" value="J2SE"> JS


<!-- ------------------------------------------------------------------------ -->

    <label>Username:</label>
    <input type="text" name="username" >

    <label>Password:</label>
    <input type="password" name="password" >

    <label>Department:</label>
    <input type="text" name="department" value="OpenSource" >

    <label>Captcha:</label>
    <input type="text" name="captcha" >
<!-- ------------------------------------------------------------------------- -->
    <div class="buttons">
        <input type="submit" value="Submit">
    </div>
</form>

</body>
</html>
