#!/bin/bash

echo "=== Synchronisation ==="

# Push vers origin (GitHub + GitLab backup)
echo "1. Push vers GitHub et GitLab backup..."
git push origin main

# Push du dossier TP3 vers gitlabFolderTP3
echo "2. Push du dossier TP3 vers GitLab spécifique..."
git subtree push --prefix=FILES/TD3 gitlabFolderTP3 main

echo "=== Terminé ==="
