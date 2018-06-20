#ifndef XTHREE_DATA_TEXTURE_HPP
#define XTHREE_DATA_TEXTURE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xtexture_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // data_texture declaration
    //

    template<class D>
    class xdata_texture : public xtexture<D>
    {
    public:

        using base_type = xtexture<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(webgldataunion<float>, derived_type, data);
        XPROPERTY(std::string, derived_type, minFilter, "NearestFilter", xenums::Filters);
        XPROPERTY(std::string, derived_type, magFilter, "NearestFilter", xenums::Filters);
        XPROPERTY(bool, derived_type, flipY, false);
        XPROPERTY(bool, derived_type, generateMipmaps, false);

        const std::vector<xw::xjson_path_type>& buffer_paths() const;

        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xdata_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using data_texture = xw::xmaterialize<xdata_texture>;

    using data_texture_generator = xw::xgenerator<xdata_texture>;

    //
    // data_texture implementation
    //

    template <class D>
    inline const std::vector<xw::xjson_path_type>&  xdata_texture<D>::buffer_paths() const
    {
        static const std::vector<xw::xjson_path_type> default_buffer_paths = { 
            { "data", "buffer" },
        };
        return default_buffer_paths;
    }

    template <class D>
    inline void xdata_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(data, state, buffers);
        xw::set_patch_from_property(minFilter, state, buffers);
        xw::set_patch_from_property(magFilter, state, buffers);
        xw::set_patch_from_property(flipY, state, buffers);
        xw::set_patch_from_property(generateMipmaps, state, buffers);
    }

    template <class D>
    inline void xdata_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(data, patch, buffers);
        xw::set_property_from_patch(minFilter, patch, buffers);
        xw::set_property_from_patch(magFilter, patch, buffers);
        xw::set_property_from_patch(flipY, patch, buffers);
        xw::set_property_from_patch(generateMipmaps, patch, buffers);
    }

    template <class D>
    inline xdata_texture<D>::xdata_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdata_texture<D>::set_defaults()
    {
        this->_model_name() = "DataTextureModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdata_texture>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xdata_texture>;
        extern template xw::xmaterialize<xthree::xdata_texture>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xdata_texture>>;
        extern template class xw::xgenerator<xthree::xdata_texture>;
        extern template xw::xgenerator<xthree::xdata_texture>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xdata_texture>>;
    #endif
#endif

#endif