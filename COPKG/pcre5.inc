@import "version.inc";
@import "outercurve.inc";

package {
    name: "pcre[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";
    
    display-name: "PCRE";
    location: "http://coapp.org/repository/${OutputFilename}";

    feed: "http://coapp.org/repository/packages.atom.xml";
    publisher: "CoApp Project";
}

files[exes] {
    root: @"..\output\${arch}\Release";
    
    include: {
        "dftables.exe",
    };
    
    trim-path: all;
};


files[dlls] {
    root: @"..\output\${arch}\LibR";
  
    include: {
        "libpcre.dll",
    };
    
    trim-path: all;
};

license[PCRE] {
    license-url: "http://www.pcre.org/licence.txt";
    license-type: "PCRE";
}

files[files-to-sign] {
    include: { 
        exes,
        dlls
    };    
}

metadata {
    summary: "PCRE";
    description:  @"Perl Compatable Regular Expressions"; 

    icon: @"pcre.png";
    
    author-version : "5.0.0.0";
    bug-tracker: "https://github.com/coapp-packages/pcre5/issues";
    stability : "0";
    licenses : {
        PCRE
    };
}

compatability-policy {
    minimum: "5.0.0.0";
    maximum: "${OneLessThanCurrent}"; // this is the default
    versions : {
        "5.0.0.0",
    }; // if not specified, find the versions by looking at the feeds and finding all the major/minor versions in range.
}

application {
    include : {
        exes,
    };
}

manifest[things-that-need-them] {
    // all of our EXEs need to get the manifest entries for the assemblies we're creating in this package
    
    assembly : {
        pcre
    };
    
    include : { 
        exes
    };
}

assembly[pcre] {
    include : {
        dlls
    };
}

package-composition {
    symlinks : { 
        exes => @"${bin}\${each.Name}" = @"${packagedir}\${each.Name}";
    };
}

signing {
    attributes : {
        company="Outercurve Foundation",
        description="pcre",
        product-name="pcre",
        product-version="${package-version}",
        file-version="${package-version}",
    };
    
    replace-signature: true; 
    include: { 
        files-to-sign
    };    
}