# Development

## Building

### Mac

    cd Build
    xcodebuild -scheme SURubyDebugger -configuration Release -derivedDataPath output

The binary will be located under: `Build/output/Build/Products/Release/SURubyDebugger.dylib`

### Windows

TODO:

## Releasing

1. Update binary versions. (VS Resource Editor)
2. Build binaries for each platform.
3. Tag commit it was built from.
4. Upload binaries to GitHub Releases.
5. Update README.md to refer to new download URL and versions.

## Automation

TODO: Setup action to publish release no GitHub when creating new tag. https://trstringer.com/github-actions-create-release-upload-artifacts/
