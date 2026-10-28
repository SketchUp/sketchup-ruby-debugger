# Development

## Building

### Mac

    cd Build
    xcodebuild -scheme SURubyDebugger -configuration Release -derivedDataPath output

The binary will be located under: `Build/output/Build/Products/Release/SURubyDebugger.dylib`

After building, the dylib is copied into the `Contents/Frameworks` directory of
`SKETCHUP_APP_PATH`, which defaults to `/Applications/SketchUp 2027/SketchUp.app`.
Override it to install into a different SketchUp, such as a local build:

    xcodebuild -scheme SURubyDebugger -configuration Release SKETCHUP_APP_PATH="/path/to/SketchUp.app"

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
