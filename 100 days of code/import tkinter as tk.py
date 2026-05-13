import tkinter as tk
from tkinter import messagebox
import sqlite3
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

class VotingSystem:
    def __init__(self, root):
        self.root = root
        self.root.title("Online Voting System")
        self.root.attributes('-fullscreen', True)
        self.root.configure(bg="#dff6ff")

        self.root.bind("<Escape>", self.exit_fullscreen)

        # Database setup
        self.conn = sqlite3.connect("votes.db")
        self.cursor = self.conn.cursor()
        self.cursor.execute("""
        CREATE TABLE IF NOT EXISTS votes (
            name TEXT,
            voter_id TEXT UNIQUE,
            candidate TEXT
        )
        """)
        self.conn.commit()

        self.candidates = ["BJP", "CONGRESS", "AAP"]

        self.create_gui()

    def exit_fullscreen(self, event):
        self.root.attributes('-fullscreen', False)

    def create_gui(self):
        frame = tk.Frame(self.root, bg="#dff6ff")
        frame.place(relx=0.5, rely=0.5, anchor="center")

        tk.Label(frame, text="ONLINE VOTING SYSTEM",
                 font=("Arial", 28, "bold"),
                 bg="#dff6ff", fg="#0077b6").pack(pady=20)

        tk.Label(frame, text="Enter Name:", bg="#dff6ff").pack()
        self.entry_name = tk.Entry(frame, width=30)
        self.entry_name.pack(pady=10)

        tk.Label(frame, text="Enter Voting ID:", bg="#dff6ff").pack()
        self.entry_id = tk.Entry(frame, width=30)
        self.entry_id.pack(pady=10)

        tk.Label(frame, text="Choose Party:",
                 font=("Arial", 14, "bold"),
                 bg="#dff6ff").pack(pady=15)

        for c in self.candidates:
            tk.Button(frame,
                      text=f"Vote {c}",
                      width=25,
                      bg="#90dbf4",
                      command=lambda x=c: self.vote(x)).pack(pady=5)

        self.status_label = tk.Label(frame, text="", bg="#dff6ff")
        self.status_label.pack(pady=15)

        tk.Button(frame, text="📊 Show Results",
                  width=25, bg="#48cae4",
                  command=self.show_results).pack(pady=5)

        tk.Button(frame, text="🗑 Reset Votes",
                  width=25, bg="#ffadad",
                  command=self.reset_votes).pack(pady=5)

        tk.Button(frame, text="❌ Exit",
                  width=25, bg="#adb5bd",
                  command=self.root.quit).pack(pady=10)

    def clear_fields(self):
        self.entry_name.delete(0, tk.END)
        self.entry_id.delete(0, tk.END)

    def vote(self, candidate):
        name = self.entry_name.get().strip()
        voter_id = self.entry_id.get().strip()

        if not name or not voter_id:
            messagebox.showerror("Error", "Fill all fields!")
            return

        if not voter_id.isdigit():
            messagebox.showerror("Error", "Voting ID must be numeric!")
            return

        try:
            self.cursor.execute("INSERT INTO votes VALUES (?, ?, ?)",
                                (name, voter_id, candidate))
            self.conn.commit()
            self.status_label.config(text=f"✅ Vote given to {candidate}", fg="green")
            self.clear_fields()
        except:
            messagebox.showwarning("Warning", "❌ This ID already voted!")

    def show_results(self):
        self.cursor.execute("SELECT candidate FROM votes")
        data = self.cursor.fetchall()

        if not data:
            messagebox.showinfo("Info", "No votes yet!")
            return

        df = pd.DataFrame(data, columns=["Candidate"])
        count = df["Candidate"].value_counts()

        votes = np.array(count.values)
        total_votes = np.sum(votes)

        messagebox.showinfo("Total Votes", f"Total Votes Cast: {total_votes}")

        plt.figure()
        plt.bar(count.index, votes)
        plt.title("Voting Results (Bar Chart)")
        plt.xlabel("Parties")
        plt.ylabel("Votes")

        plt.figure()
        plt.pie(votes, labels=count.index, autopct="%1.1f%%")
        plt.title("Voting Results (Pie Chart)")

        plt.show()

    def reset_votes(self):
        if messagebox.askyesno("Confirm", "Delete all votes?"):
            self.cursor.execute("DELETE FROM votes")
            self.conn.commit()
            messagebox.showinfo("Reset", "All votes deleted!")


# Main Program
root = tk.Tk()
app = VotingSystem(root)
root.mainloop()