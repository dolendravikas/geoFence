const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <style type="text/css">
    body {
        background-image: url('https://images.unsplash.com/photo-1488866022504-f2584929ca5f?auto=format&fit=crop&w=1486&q=80&ixid=dW5zcGxhc2guY29tOzs7Ozs%3D');
        background-size: cover;
        margin: 0;
        background-repeat: no-repeat;
        background-position: 0 0;
        transition: 2s cubic-bezier(0.645, 0.045, 0.355, 1);
        color :white;
    }

    hr {
        visibility: visible;
        border: 0;
        height: 1px;
        background-image: linear-gradient(to right, rgba(255, 255, 255, 0), rgba(255, 255, 255, 0.75), rgba(255, 255, 255, 0));
    }

    .button {
      background-color: rgba(55, 72, 87, 0.8); 
      border: none;
      color: white;
      padding: 12px 20px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      border-radius: 12px;
      font-size: 16px;
    }
  </style>

  <body style="background-color: #ffffff ; font-family:verdana">
    
    <center>
      <p>Device Status <span id = "Device_status" style="color : rgba(0, 255, 106, 0.857);">offline</span></p>
      <hr style = "width: 70%;">
      <h1>Dashboard</h1>
      <hr style = "width: 70%;">
      <div>
        <button class="button" onclick="send(1)">Fence 1</button>
        <button class="button" onclick="send(2)">Fence 2</button>
        <p>Selected Fence: <span id="fence_id">0</span><br></p>
      </div>
      <hr style = "width: 40%;">
      <div style="background-color: rgba(89, 154, 211, 0.3);; width: 30%; border-radius: 12px;">
          <table style="text-align: center; " >
              <tr>
                  <th style="padding: 0 20px 0 20px;">Date</th>
                  <th style="padding: 0 20px 0 20px;">No.of Sats</th>
              </tr>
              <tr>
                  <td><span id="date">0</span><br></td>
                  <td><span id="sats">0</span><br></td>
              </tr>
          </table>
      </div>
      <hr style = "width: 40%;">
      <div>
        <div style="background-color: rgba(89, 154, 211, 0.3); display: inline-block; width: 10%; border-radius: 12px;">
            <table style="text-align: center; " >
                <tr>
                    <th>Latitude</th>
                </tr>
                <tr>
                    <td><span id="lat_val">0</span><br></td>
                </tr>
                <tr>
                    <th>Longitude</th>
                </tr>
                <tr>
                    <td><span id="lon_val">0</span><br></td>
                </tr>
            </table>
          </div>
          <div style="background-color: rgba(89, 154, 211, 0.3); display: inline-block; width: 15%; border-radius: 12px;">
            <table style="text-align: center; " >
                <tr>
                    <th>Target Status</th>
                </tr>
                <tr>
                    <td><span id="target_status">0</span><br></td>
                </tr>
                <tr>
                    <th>Cumulative Angle</th>
                </tr>
                <tr>
                    <td><span id="angle">0</span><br></td>
                </tr>
            </table>
          </div>
      </div>
      <hr style = "width: 70%;">
      <script>
        function send(fence_val) {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              document.getElementById("fence_id").innerHTML = this.responseText;
            }
          };
          xhttp.open("GET", "status?fenceValue="+fence_val, true);
          xhttp.send();
        }

        setInterval(function() {getData();}, 2000); 

        function getData() {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              const data = this.responseText.split("#");
              document.getElementById("date").innerHTML = data[1];
              document.getElementById("sats").innerHTML = data[0];
              document.getElementById("lat_val").innerHTML = data[2];
              document.getElementById("lon_val").innerHTML = data[3];
              document.getElementById("target_status").innerHTML = data[4];
              document.getElementById("angle").innerHTML = data[5];
              document.getElementById("Device_status").innerHTML = data[6];             
            }
          };
          xhttp.open("GET", "values", true);
          xhttp.send();
        }
      </script>
    </center>
  </body>
</html>
)=====";