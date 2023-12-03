  
function validate() {
            var user = document.getElementById('username').value
            var pass = document.getElementById('password').value
            if (user == "itmbu" && pass == "itmb@123") {
                window.open("home_page.html")
                
            } else {
                alert('incorrect username or password')
            }
        }
