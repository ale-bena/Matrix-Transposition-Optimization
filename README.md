# Matrix-Transposition-Optimization

# Features <!-- omit in toc -->

- [GitHub Stats Card]
    - [Hiding individual stats]
 
# README

## Instructions for Running on Windows

### Step 1: Install MobaXterm

1. Download **MobaXterm Home Edition v24.3**:
   - Go to [MobaXterm Official Website](https://mobaxterm.mobatek.net/).
   - Click on **GET MOBAXTERM NOW!**.
   - Select the **Free Edition** and download the **MobaXterm Home Edition v24.3 (Installer edition)**.

2. Install MobaXterm:
   - Unzip the downloaded folder.
   - Open the unzipped folder and double-click on the file: `MobaXterm_installer_24.3`.
   - Follow the installation steps:
     - Click **Next** on the first screen.
     - Accept the terms and click **Next**.
     - Keep the default folder and click **Next** again.
     - Click **Install**.
   - Grant permission to modify your computer by clicking **Yes**.
   - When the installation finishes, click **Finish**.

   > **Note:** We will open MobaXterm later in the process.

---

### Step 2: Install GlobalProtect VPN

1. Download **GlobalProtect**:
   - Visit the [GlobalProtect download page](https://vpn.youruniversitydomain.com/).
   - Select the version compatible with your system (32-bit or 64-bit) based on the instructions on the page.

2. Install GlobalProtect:
   - Run the downloaded file.
   - Click **Next** on the three setup screens to proceed.
   - Grant permission to modify your computer by clicking **Yes**.
   - Once the installation is complete, click **Close**.

---

### Step 3: Connect to the University Network via VPN

1. Locate the **GlobalProtect** icon:
   - Click the up arrow on the bottom-right corner of the taskbar.
   - Look for the **grey globe** icon and click on it.

2. Connect to the VPN:
   - In the **Portal** field, type or paste: `vpn-mfa.icts.unitn.it`.
   - Click **Connect**.
   - When prompted, log in with your university account credentials or use **SPID** if requested.

---

### Step 4: Proceed with GitHub and HPC Setup

When the VPN is activated, proceed with the following steps:

1. Open the GitHub link: [Matrix Transposition Optimization](https://github.com/ale-bena/Matrix-Transposition-Optimization.git).
2. Click the green **Code** button and select **Download ZIP**.
3. Unzip the folder.

---

### Step 5: Configure MobaXterm for HPC Access

1. **Open MobaXterm** and start a new local session.
2. If Windows Defender prompts you to choose network settings, select **Private Networks** for safety.

3. Connect to the HPC cluster:
   ```bash
   ssh name.surname@hpc.unitn.it

