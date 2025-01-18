package com.example.basickotlinapplication

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    private var count = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)

        // System bars
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        // Navigate to second activity
        findViewById<Button>(R.id.next_button).setOnClickListener {
            val intent = Intent(this, MainActivity2::class.java)
            startActivity(intent);
        }

        // Toast display
        findViewById<Button>(R.id.toast_button).setOnClickListener {
            Toast.makeText(this, "Hello from MainActivity!", Toast.LENGTH_SHORT).show()
        }

        val countTextView = findViewById<TextView>(R.id.count_text)

        findViewById<Button>(R.id.count_button).setOnClickListener {
            count++
            countTextView.text = count.toString()
        }


    }
}