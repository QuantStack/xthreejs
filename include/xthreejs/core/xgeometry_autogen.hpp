#ifndef XTHREE_GEOMETRY_HPP
#define XTHREE_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xbase_geometry_autogen.hpp"

namespace xthree
{
    //
    // geometry declaration
    //

    template<class D>
    class xgeometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::vector<std::vector<double>>, derived_type, vertices, std::vector<std::vector<double>>({}));
        XPROPERTY(std::vector<xw::html_color>, derived_type, colors, std::vector<xw::html_color>({"#ffffff"}));
        XPROPERTY(std::vector<face3>, derived_type, faces, std::vector<face3>({}));
        XPROPERTY(std::vector<double>, derived_type, faceVertexUvs, std::vector<double>({}));
        XPROPERTY(std::vector<double>, derived_type, lineDistances, std::vector<double>({}));
        XPROPERTY(std::vector<double>, derived_type, morphTargets, std::vector<double>({}));
        XPROPERTY(std::vector<double>, derived_type, morphNormals, std::vector<double>({}));
        XPROPERTY(std::vector<std::vector<double>>, derived_type, skinWeights, std::vector<std::vector<double>>({}));
        XPROPERTY(std::vector<std::vector<double>>, derived_type, skinIndices, std::vector<std::vector<double>>({}));
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, _ref_geometry);


    protected:

        xgeometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using geometry = xw::xmaterialize<xgeometry>;

    using geometry_generator = xw::xgenerator<xgeometry>;

    //
    // geometry implementation
    //


    template <class D>
    inline void xgeometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(vertices, state, buffers);
        xw::set_patch_from_property(colors, state, buffers);
        xw::set_patch_from_property(faces, state, buffers);
        xw::set_patch_from_property(faceVertexUvs, state, buffers);
        xw::set_patch_from_property(lineDistances, state, buffers);
        xw::set_patch_from_property(morphTargets, state, buffers);
        xw::set_patch_from_property(morphNormals, state, buffers);
        xw::set_patch_from_property(skinWeights, state, buffers);
        xw::set_patch_from_property(skinIndices, state, buffers);
        xw::set_patch_from_property(_ref_geometry, state, buffers);
    }

    template <class D>
    inline void xgeometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(vertices, patch, buffers);
        xw::set_property_from_patch(colors, patch, buffers);
        xw::set_property_from_patch(faces, patch, buffers);
        xw::set_property_from_patch(faceVertexUvs, patch, buffers);
        xw::set_property_from_patch(lineDistances, patch, buffers);
        xw::set_property_from_patch(morphTargets, patch, buffers);
        xw::set_property_from_patch(morphNormals, patch, buffers);
        xw::set_property_from_patch(skinWeights, patch, buffers);
        xw::set_property_from_patch(skinIndices, patch, buffers);
        xw::set_property_from_patch(_ref_geometry, patch, buffers);
    }

    template <class D>
    inline xgeometry<D>::xgeometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xgeometry<D>::set_defaults()
    {
        this->_model_name() = "GeometryModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xgeometry>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xgeometry>>;
    extern template class xw::xgenerator<xthree::xgeometry>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xgeometry>>;
#endif

#endif