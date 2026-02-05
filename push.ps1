#!/bin/bash

echo "=== Synchronisation ==="

# Push vers origin (GitHub + GitLab backup)
echo "1. Push vers GitHub et GitLab backup..."
git push origin main

# Push du dossier TD3 vers GitLab spécifique (sur master avec force)
Write-Host "2. Push du dossier TD3 vers GitLab spécifique..."
$split = git subtree split --prefix=FILES/TD3 main
git push gitlabFolderTD3 "${split}:refs/heads/master" # --force

echo "=== Terminé ==="
