package com.example.bluetoothhomeautomation;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.view.MotionEvent;
import androidx.appcompat.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    public final static String MODULE_MAC = "00:20:10:08:FC:39";
    public final static int REQUEST_ENABLE_BT = 1;
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");

    BluetoothAdapter bta;
    BluetoothSocket mmSocket;
    BluetoothDevice mmDevice;
    ConnectedThread btt = null;
    Button bt, sw, btFan, btBulb, btTubeLight;
    boolean btState = false, fanState = false, bulbState = false, tubeLightState = false;
    TextView response;
    public Handler mHandler;

    @SuppressLint("ClickableViewAccessibility")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.i("[BLUETOOTH]", "Creating listeners");
        response = findViewById(R.id.response);
        bt = findViewById(R.id.bluetooth);
        sw = findViewById(R.id.sw);
        btFan = findViewById(R.id.fan);
        btBulb = findViewById(R.id.bulb);
        btTubeLight = findViewById(R.id.tubelight);

        btFan.setEnabled(false);
        btBulb.setEnabled(false);
        btTubeLight.setEnabled(false);

        bt.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN) {
                    if (mmSocket.isConnected() && btt != null) {  // if we have connection to the bluetooth module
                        if (btState) {
                            String sendTxt = "SW";
                            btState = false;
                            btt.write(sendTxt.getBytes());
                            sw.setBackgroundResource(R.drawable.switch_button_pressed);
                            bt.setBackgroundResource(R.drawable.bluetooth_button);

                            btFan.setEnabled(false);
                            btBulb.setEnabled(false);
                            btTubeLight.setEnabled(false);

                            btFan.setSelected(false);
                            btBulb.setSelected(false);
                            btTubeLight.setSelected(false);
                        } else {
                            String sendTxt = "BT";
                            btState = true;
                            btt.write(sendTxt.getBytes());
                            sw.setBackgroundResource(R.drawable.switch_button);
                            bt.setBackgroundResource(R.drawable.bluetooth_button_pressed);
                            btFan.setEnabled(true);
                            btBulb.setEnabled(true);
                            btTubeLight.setEnabled(true);
                        }
                    } else {
                        btState = false;
                        sw.setBackgroundResource(R.drawable.switch_button_pressed);
                        bt.setBackgroundResource(R.drawable.bluetooth_button);
                        btFan.setEnabled(false);
                        btBulb.setEnabled(false);
                        btTubeLight.setEnabled(false);
                        Toast.makeText(MainActivity.this, "Bluetooth is not connected or has been disconnected", Toast.LENGTH_LONG).show();
                    }
                }
                return false;
            }
        });

        sw.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN) {
                    if (mmSocket.isConnected() && btt != null) {  // if we have connection to the bluetooth module
                        if (btState) {
                            String sendTxt = "SW";
                            btState = false;
                            btt.write(sendTxt.getBytes());
                            sw.setBackgroundResource(R.drawable.switch_button_pressed);
                            bt.setBackgroundResource(R.drawable.bluetooth_button);

                            btFan.setEnabled(false);
                            btBulb.setEnabled(false);
                            btTubeLight.setEnabled(false);
                        }
                    } else {
                        btState = false;
                        sw.setBackgroundResource(R.drawable.switch_button_pressed);
                        bt.setBackgroundResource(R.drawable.bluetooth_button);

                        btFan.setEnabled(false);
                        btBulb.setEnabled(false);
                        btTubeLight.setEnabled(false);
                        Toast.makeText(MainActivity.this, "Bluetooth is not connected or has been disconnected", Toast.LENGTH_LONG).show();
                    }
                }
                return false;
            }
        });

        btFan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (fanState) {
                    fanState = false;
                    String sendTxt = "F0";
                    btt.write(sendTxt.getBytes());

                    btFan.setSelected(false);

                } else {
                    fanState = true;
                    String sendTxt = "F1";
                    btt.write(sendTxt.getBytes());

                    btFan.setSelected(true);

                    btFan.setEnabled(false);
                    btBulb.setEnabled(false);
                    btTubeLight.setEnabled(false);

                }

                btFan.setClickable(false);
                btBulb.setClickable(false);
                btTubeLight.setClickable(false);
            }
        });

        btBulb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (bulbState) {
                    bulbState = false;
                    String sendTxt = "B0";
                    btt.write(sendTxt.getBytes());

                    btBulb.setSelected(false);

                } else {
                    bulbState = true;
                    String sendTxt = "B1";
                    btt.write(sendTxt.getBytes());

                    btBulb.setSelected(true);

                }

                btFan.setClickable(false);
                btBulb.setClickable(false);
                btTubeLight.setClickable(false);
            }
        });

        btTubeLight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (tubeLightState) {
                    tubeLightState = false;
                    String sendTxt = "T0";
                    btt.write(sendTxt.getBytes());

                    btTubeLight.setSelected(false);

                } else {
                    tubeLightState = true;
                    String sendTxt = "T1";
                    btt.write(sendTxt.getBytes());

                    btTubeLight.setSelected(true);

                }

                btFan.setClickable(false);
                btBulb.setClickable(false);
                btTubeLight.setClickable(false);
            }
        });

        bta = BluetoothAdapter.getDefaultAdapter();

        // If bluetooth is not enabled then create Intent for user to turn it on
        if (!bta.isEnabled()) {
            Intent enableBTIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBTIntent, REQUEST_ENABLE_BT);
        } else {
            initiateBluetoothProcess();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (resultCode == RESULT_OK && requestCode == REQUEST_ENABLE_BT) {
            initiateBluetoothProcess();
        }
    }

    public void initiateBluetoothProcess() {
        if (bta.isEnabled()) {
            // attempt to connect to bluetooth module
            BluetoothSocket tmp = null;
            mmDevice = bta.getRemoteDevice(MODULE_MAC);

            // create socket
            try {
                tmp = mmDevice.createRfcommSocketToServiceRecord(MY_UUID);
                mmSocket = tmp;
                mmSocket.connect();
                Log.i("[BLUETOOTH]", "Connected to: " + mmDevice.getName());
                Toast.makeText(MainActivity.this, "Bluetooth module connected", Toast.LENGTH_LONG).show();
            } catch (IOException e) {
                try {
                    mmSocket.close();
                } catch (IOException c) {
                    return;
                }
            }

            Log.i("[BLUETOOTH]", "Creating handler");
            mHandler = new Handler(Looper.getMainLooper()) {
                @Override
                public void handleMessage(Message msg) {
                    // super.handleMessage(msg);
                    if (msg.what == ConnectedThread.RESPONSE_MESSAGE) {
                        String txt = (String) msg.obj;
                        if (response.getText().toString().length() >= 180) {
                            response.setText("");
                            response.append(txt);

                        } else {
                            response.append("\n" + txt);

                        }

                        btFan.setClickable(true);
                        btBulb.setClickable(true);
                        btTubeLight.setClickable(true);
                    }
                }
            };

            Log.i("[BLUETOOTH]", "Creating and running Thread");
            btt = new ConnectedThread(mmSocket, mHandler);
            btt.start();
        }
    }
}