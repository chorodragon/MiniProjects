package com.example.antonio.petcare;

import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

public class Login extends AppCompatActivity {

    //Variables
    private Button mLoginButton;
    private Button mRegisterButton;
    private EditText mEditUser;
    private EditText mEditPassword;

    //Firebase variables
    private FirebaseAuth mAuth;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        mLoginButton = (Button) findViewById(R.id.button_login_login);
        mRegisterButton = (Button) findViewById(R.id.button_login_register);
        mEditPassword = (EditText) findViewById(R.id.edit_login_password);
        mEditUser = (EditText) findViewById(R.id.edit_login_username);

        mAuth = FirebaseAuth.getInstance();

        mLoginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                attemptLogin();
            }
        });

        mRegisterButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                registerUser();
                finish();
            }
        });
    }

    private void registerUser() {
        Intent intent = new Intent(this, Register.class);
        startActivity(intent);
    }

    private void attemptLogin(){
        String email = mEditUser.getText().toString();
        String password = mEditPassword.getText().toString();

        if (email.isEmpty()){
            mEditUser.setError("Ingrese su direccion de correo");
            return;
        }
        if (password.isEmpty()){
            mEditPassword.setError("Ingrese su contrasena");
            return;
        }

        Toast.makeText(this, "Logging in progress...", Toast.LENGTH_SHORT).show();

        mAuth.signInWithEmailAndPassword(email, password).addOnCompleteListener(this, new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                Log.d("Pet", "signInWith Email and password " + task.isSuccessful());

                if(!task.isSuccessful()){
                    Log.d("Pet", "Sign in failed " + task.getException());
                    showErrorDialog("There was a problem with sign in.");
                }
                else {
                    Intent intent = new Intent(Login.this, MainActivity.class);
                    finish();
                    startActivity(intent);
                }
            }
        });
    }

    private void showErrorDialog(String message) {
        new AlertDialog.Builder(this)
                .setTitle("Error")
                .setMessage(message)
                .setPositiveButton(R.string.positiveButton, null)
                .show();
    }
}
