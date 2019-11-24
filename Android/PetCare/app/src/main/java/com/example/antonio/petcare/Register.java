package com.example.antonio.petcare;

import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

public class Register extends AppCompatActivity {

    //Variables
    EditText mEditEmail;
    EditText mEditPassword;
    EditText mEditPasswordRepeat;

    Button mButtonRegister;
    Button mButtonCancel;

    //Firebase variables
    private FirebaseAuth mAuth;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        mEditEmail = (EditText) findViewById(R.id.edit_register_email);
        mEditPassword = (EditText) findViewById(R.id.edit_register_password);
        mEditPasswordRepeat = (EditText) findViewById(R.id.edit_register_passwordRepeat);

        mButtonCancel = (Button) findViewById(R.id.button_register_cancel);
        mButtonRegister = (Button) findViewById(R.id.button_register_register);

        mAuth = FirebaseAuth.getInstance();

        mButtonRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                attemptRegistration();
            }
        });

        mButtonCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                cancelRegister();
            }
        });
    }

    private void attemptRegistration() {

        // Reset errors displayed in the form.
        mEditEmail.setError(null);
        mEditPassword.setError(null);

        // Store values at the time of the login attempt.
        String email = mEditEmail.getText().toString();
        String password = mEditPassword.getText().toString();

        boolean cancel = false;
        View focusView = null;

        if(!isEmailValid(email)) {
            mEditEmail.setError(getString(R.string.error_field_required));
            focusView = mEditEmail;
            cancel = true;
        }

        if(!isPasswordValid(password)) {
            mEditPassword.setError(getString(R.string.error_invalid_password));
            focusView = mEditPassword;
            cancel = true;
        }

        if (cancel) {
            // There was an error; don't attempt login and focus the first
            // form field with an error.
            focusView.requestFocus();
        } else {
            // TODO: Call create FirebaseUser() here
            createFirebaseUser();

        }
    }

    private void cancelRegister() {
        Intent intent = new Intent(this, Login.class);
        startActivity(intent);
        finish();
    }

    private boolean isEmailValid(String email) {
        return !email.isEmpty() && email.contains("@");
    }

    private boolean isPasswordValid(String password) {
        String confirmPassword = mEditPasswordRepeat.getText().toString();
        return password.equals(confirmPassword) && password.length() > 6;
    }

    private void createFirebaseUser() {
        String userEmail = mEditEmail.getText().toString();
        String userPassword = mEditPassword.getText().toString();

        mAuth.createUserWithEmailAndPassword(userEmail, userPassword).addOnCompleteListener(this, new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                Log.d("Pet", "createOnUser " + task.isSuccessful());

                if(!task.isSuccessful()) {
                    Log.d("Pet", "Registration failed" + task.getException());
                    showErrorDialog("Error al registrar el nuevo usuario");
                }
                else{
                    Intent intent = new Intent(Register.this, Login.class);
                    finish();
                    startActivity(intent);
                }
            }
        });

    }

    private void showErrorDialog(String message) {
        new AlertDialog.Builder(this)
                .setTitle("Error en el registro")
                .setMessage(message)
                .setPositiveButton(R.string.positiveButton, null)
                .show();
    }
}
